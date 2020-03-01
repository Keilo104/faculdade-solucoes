<?php
	include("util.php");	
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<title>FORM PHP</title>
	<link rel="stylesheet" type="text/css" href="css/estilo.css">
</head>
<body>
	<div id="conteudo">
		<header id="cabecalho">
			<h1>PHP　フォーム</h1>
			<nav id="menu">
				<ul>
					<a href="index.php"><li>PHP　フォーム</li></a>
					<a href="#"><li>二ページ</li></a>
					<a href="#"><li>三ページ</li></a>
				</ul>
			</nav>
		</header>
		<section id="principal">
			<?php 
				if(isset($_GET["msg"])) {
					$erros = explode(";", $_GET["msg"]);
					array_pop($erros);

					echo "<div class='erro'><ul>";
					foreach($erros as $key => $value) {
						echo "<li>".$value."</li>";
					}
					echo "</div></ul><br/>";
				}
			?>

			<div id="calculadora" class="contorno">
				<form action="recebeForm.php" method="POST">
					<div id="divFormEsq">
					    <label for="fname">名前</label>
					    <input type="text" id="fname" name="firstname" placeholder="名前">

					    <label for="sname">名字</label>
					    <input type="text" id="sname" name="surname" placeholder="名字">
					    
					    <label for="country">国</label>
					    <select id="country" name="country">
					      <option value="NULL"></option>	
					      <option value="australia">オーストラリア</option>
					      <option value="canada">カナダ</option>
					      <option value="brasil">ブラジル</option>
					      <option value="usa">アメリカ</option>
					    </select>

					    <label for="cursos">副専攻</label><br/>
					    <input type="checkbox" name="cursos[]" value="PHP" id="cPHP"><label for="cPHP">PHP</label><br/>
					    <input type="checkbox" name="cursos[]" value="HTML" id="cHTML"><label for="cHTML">HTML</label><br/>
					    <input type="checkbox" name="cursos[]" value="CSS" id="cCSS"><label for="cCSS">CSS</label><br/>
				    </div>

				    <div id="divFormDir">
					    <label for="email">電子メール</label>
					    <input type="text" id="email" name="email" placeholder="電子メール">

					    <label for="password">合言葉</label>
					    <input type="password" id="password" name="password" placeholder="合言葉">

					    <label for="cnumber">携番</label>
					    <input type="text" id="cnumber" name="cnumber" placeholder="携番">
				    </div>
				  	<br style="clear: both">
				    <input type="submit" value="差し出す" id="submit">
			  	</form>
			</div>
		</section>
		<footer>
			Sistema desenvolvido por Rodrigo Henrique Ramos - 2020A
		</footer>
	</div>
</body>
</html>