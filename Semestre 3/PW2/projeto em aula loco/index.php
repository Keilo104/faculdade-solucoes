<?php
	include("includes/util.php");
	session_start();
	session_destroy();

	if(!$_SESSION) {
		make_session();
	}
	include("includes/cabecalho.php");
?>

<body>
	<div id="conteudo">
		<header id="cabecalho">
			<h1>FORM PHP 1</h1>
			<?php include("includes/menu.php"); ?>
		<section id="principal">
			<?php 
				if(isset($_GET["msg"])) {
					if($_GET["msg"] != "success") {
						$erros = explode(";", $_GET["msg"]);
						array_pop($erros);


						echo "<div class='erro'><ul>";
						foreach($erros as $key => $value) {
							echo "<li>".$value."</li>";
						}
						echo "</div></ul><br/>";
					} else {
						echo "<div class='success'>Sucesso!</div><br/>";
					}
				}
			?>

			<div id="calculadora" class="contorno">
				<form action="recebeForm.php" method="POST">
					<div id="divFormEsq">
					    <label for="fname">名前</label>
					    <input type="text" id="fname" name="firstname" placeholder="名前" value=<?=$_SESSION["firstname"]; ?>>

					    <label for="sname">名字</label>
					    <input type="text" id="sname" name="surname" placeholder="名字" value=<?=$_SESSION["surname"]; ?>>
					    
					    <label for="country">国</label>
					    <select id="country" name="country">
					      <option value="NULL" <?php if($_SESSION["country"] == "NULL") echo "selected"; ?>></option>	
					      <option value="australia" <?php if($_SESSION["country"] == "australia") echo "selected"; ?>>オーストラリア</option>
					      <option value="canada" <?php if($_SESSION["country"] == "canada") echo "selected"; ?>>カナダ</option>
					      <option value="brasil" <?php if($_SESSION["country"] == "brasil") echo "selected"; ?>>ブラジル</option>
					      <option value="usa" <?php if($_SESSION["country"] == "usa") echo "selected"; ?>>アメリカ</option>
					    </select>

					    <label for="cursos">副専攻</label><br/>
					    <input type="checkbox" name="cursos[]" value="PHP" id="cPHP" <?php if(in_array("PHP", $_SESSION["cursos"])) echo "checked"; ?>><label for="cPHP">PHP</label><br/>
					    <input type="checkbox" name="cursos[]" value="HTML" id="cHTML" <?php if(in_array("HTML", $_SESSION["cursos"])) echo "checked"; ?>><label for="cHTML">HTML</label><br/>
					    <input type="checkbox" name="cursos[]" value="CSS" id="cCSS" <?php if(in_array("CSS", $_SESSION["cursos"])) echo "checked"; ?>><label for="cCSS">CSS</label><br/>
				    </div>

				    <div id="divFormDir">
					    <label for="email">電子メール</label>
					    <input type="text" id="email" name="email" placeholder="電子メール" value=<?=$_SESSION["email"]; ?>>

					    <label for="password">合言葉</label>
					    <input type="password" id="password" name="password" placeholder="合言葉">

					    <label for="cnumber">携番</label>
					    <input type="text" id="cnumber" name="cnumber" placeholder="携番" value=<?=$_SESSION["cnumber"]; ?>>
				    </div>
				  	<br style="clear: both">
				    <input type="submit" value="差し出す" id="submit">
			  	</form>
			</div>
		</section>
		<?php include("includes/footer.php"); ?>
	</div>
</body>
</html>