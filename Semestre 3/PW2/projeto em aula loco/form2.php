<?php
	include("includes/util.php");
	include("includes/cabecalho.php");
?>
<body>
	<div id="conteudo">
		<header id="cabecalho">
			<h1>FORM PHP 2</h1>
			<?php include("includes/menu.php"); ?>
		</header>
		<section id="principal">
			<form>
			  <div class="form-row">
			    <div class="form-group col-md-6">
			      <label for="inputEmail4">Email <i class="far fa-envelope"></i></label>
			      <input type="email" class="form-control" id="inputEmail4" placeholder="Email">
			    </div>
			    <div class="form-group col-md-6">
			      <label for="inputPassword4">Password <i class="fas fa-key"></i></label>
			      <input type="password" class="form-control" id="inputPassword4" placeholder="Password">
			    </div>
			  </div>
			  <div class="form-group">
			    <label for="inputAddress">Address <i class="fas fa-address-card"></i></label>
			    <input type="text" class="form-control" id="inputAddress" placeholder="1234 Main St">
			  </div>
			  <div class="form-group">
			    <label for="inputAddress2">Address 2 <i class="fas fa-address-card"></i></label>
			    <input type="text" class="form-control" id="inputAddress2" placeholder="Apartment, studio, or floor">
			  </div>
			  <div class="form-row">
			    <div class="form-group col-md-6">
			      <label for="inputCity">City</label>
			      <input type="text" class="form-control" id="inputCity">
			    </div>
			    <div class="form-group col-md-4">
			      <label for="inputState">State</label>
			      <select id="inputState" class="form-control">
			        <option selected>Choose...</option>
			        <option>...</option>
			      </select>
			    </div>
			    <div class="form-group col-md-2">
			      <label for="inputZip">Zip</label>
			      <input type="text" class="form-control" id="inputZip">
			    </div>
			  </div>
			  <div class="form-group">
			    <div class="form-check">
			      <input class="form-check-input" type="checkbox" id="gridCheck">
			      <label class="form-check-label" for="gridCheck">
			        Check me out
			      </label>
			    </div>
			  </div>
			  <button type="submit" class="btn btn-primary">Sign in</button>
			</form>
		</section>
		<?php include("includes/footer.php"); ?>
	</div>
	
	<script type="text/javascript" src="js/js.js"></script>
</body>
</html>