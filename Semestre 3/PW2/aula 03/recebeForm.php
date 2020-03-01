<?php
include("util.php");

debug($_POST);

$erro = "";

if($_POST["firstname"] == "") {
	$erro .= "Informe o primeiro nome;";
}

if($_POST["surname"] == "") {
	$erro .= "Informe o último nome;";
}

if($_POST["email"] == "") {
	$erro .= "Informe o email;";
}

if($_POST["password"] == "") {
	$erro .= "Informe a senha;";
}

if($_POST["cnumber"] == "") {
	$erro .= "Informe o número de celular;";
}

if(($_POST["password"] == $_POST["firstname"] || $_POST["password"] == $_POST["surname"]) && $_POST["password"] != "") {
	$erro .= "Escolha uma senha mais forte;";
}

if(!array_key_exists("cursos", $_POST)) {
	$erro .= "Escolha ao menos 1 curso;";
}

if(!$erro) {
	$erro = "success";
}

header("Location:index.php?msg=" . $erro);