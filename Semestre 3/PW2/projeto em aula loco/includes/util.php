<?php

function debug($param){
  echo "<pre>";
  print_r($param);
  echo "</pre>";
}

function make_session() {
	$_SESSION["firstname"] = "";
	$_SESSION["surname"] = "";
	$_SESSION["country"] = "NULL";
	$_SESSION["cnumber"] = "";
	$_SESSION["cursos"] = Array();
	$_SESSION["email"] = "";
}