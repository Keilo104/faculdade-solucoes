<?php
include("util.php");
session_start();

//debug($_POST);

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

if($_POST["country"] == "NULL") {
	$erro .= "Informe o país;";
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
	session_destroy();
} else {
	$_SESSION["firstname"] = $_POST["firstname"];
	$_SESSION["surname"] = $_POST["surname"];
	$_SESSION["country"] = $_POST["country"];
	$_SESSION["cnumber"] = $_POST["cnumber"];
	$_SESSION["cursos"] = $_POST["cursos"];
	$_SESSION["email"] = $_POST["email"];
}

header("Location:index.php?msg=" . $erro);