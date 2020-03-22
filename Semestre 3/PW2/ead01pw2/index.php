<html>

   <head>
      <title>Arquivo com PHP</title>
   </head>
   
   <body>
      
      <?php
         function debug($param){
            echo "<pre>";
            print_r($param);
            echo "</pre>";
         }

         $caminhoArquivo = "./arquivos/funcionario.csv";
         $caminhoDep = "./arquivos/departamento.csv";
         //Abre como apenas leitura ("r")
         $arquivo = fopen( $caminhoArquivo, "r" );
         $arquivoDep = fopen($caminhoDep, "r");
         
         if( $arquivo == false || $arquivoDep == false) {
            //Provavelmente vai cair aqui se o arquivo não existir 
            //ou se não tiver permissão para abrir o arquivo (Linux)
            echo ("Erro ao abrir o arquivo");
            exit();
         }

         $deps = [];

         fgets($arquivoDep);

         //não sei se é necessário a primeira linha de legenda em json, mas tá aqui caso necessário
         /*$dep = [];

         $dep["numero"] = "numero";
         $dep["nome"] = "nome";
         $dep["numeroFuncGer"] = "numeroFuncGer";
         $dep["dataIni"] = "dataIni";
         $dep["mediaSal"] = "mediaSalario";

         array_push($deps, $dep);*/

         while(($linha = fgets($arquivoDep)) !== FALSE) {
            $dep = [];
            $linha = str_replace('"', '', $linha);
            $linhaExplodida = explode(';',$linha);
            $dep["numero"] = $linhaExplodida[0];
            $dep["nome"] = $linhaExplodida[1];
            $dep["numeroFuncGer"] = $linhaExplodida[2];
            $dep["dataIni"] = substr($linhaExplodida[3], 0, -2);
            $dep["mediaSal"] = 0;

            $dep["qtdFunc"] = 0;
            $dep["salarioTotal"] = 0;
            array_push($deps, $dep);
         }

         $funcionarios = [];

         fgets($arquivo);

         //não sei se é necessário a primeira linha de legenda em json, mas tá aqui caso necessário
         /*$funcionario = [];

         $funcionario["id"] = "numero";
         $funcionario["nome"] = "nome";
         $funcionario["salario"] = "salario";
         $funcionario["idDepartamento"] = "numerodepto";
         $funcionario["nomeDepartamento"] = "nomedepto";
         array_push($funcionarios, $funcionario);*/

         while (($linha = fgets($arquivo)) !== FALSE) {
            $funcionario = [];
            $linha=str_replace('"', '', $linha);
            $linhaExplodida = explode(';',$linha);
            //Cria um array associativo para o funcionario atual
            $funcionario["id"] = $linhaExplodida[0];
            $funcionario["nome"] = $linhaExplodida[1];
            $funcionario["salario"] = $linhaExplodida[6];
            $funcionario["idDepartamento"] = substr($linhaExplodida[8], 0, -2);
            $funcionario["nomeDepartamento"] = "Departamento não encontrado";

            foreach ($deps as $key => &$value) {
               if($value["numero"] == $funcionario["idDepartamento"]) {
                  $funcionario["nomeDepartamento"] = $value["nome"];
                  $value["qtdFunc"]++;
                  $value["salarioTotal"] += $funcionario["salario"];
                  break;
               }
            }

            array_push($funcionarios, $funcionario);
         }

         foreach ($deps as $key => &$value) {
            if(array_key_exists("qtdFunc", $value)) {
               $value["mediaSal"] = $value["salarioTotal"] / $value["qtdFunc"];
               unset($value["qtdFunc"]);
               unset($value["salarioTotal"]);
            }
         }

         //Fecha o arquivo csv
         fclose($arquivo);
         fclose($arquivoDep);

         debug($funcionarios);
         debug($deps);

         //Transforma em JSON e salva no arquivo.
         $deps = json_encode($deps);
         $funcionarios = json_encode($funcionarios);
         debug($deps);
         debug($funcionarios);

         $filename = "./arquivos/funcionarios.json";
         $filenameDep = "./arquivos/departamentos.json";
         $file = fopen($filename, "w");
         $fileDep = fopen($filenameDep, "w");
         
         if($file == false || $fileDep == false) {
            echo ( "Erro ao abrir o arquivo" );
            exit();
         }
         
         fwrite($file, $funcionarios);
         fwrite($fileDep, $deps);
         fclose($file);
         fclose($fileDep);

      ?>
      
   </body>
</html>