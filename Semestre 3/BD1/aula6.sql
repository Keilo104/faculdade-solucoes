CREATE TABLE empregado (
	codigo INT NOT NULL,
	nome VARCHAR(60) NOT NULL,
	cpf VARCHAR(14) NOT NULL,
	sexo CHAR(1),
	datanasc DATE,
	logradouro VARCHAR(50),
	nro INT,
	salario DECIMAL(8, 2) NOT NULL,
	depto_num INT,
	codigo_ger INT,

	CONSTRAINT empregado_pk PRIMARY KEY (codigo),
	CONSTRAINT empregado_sexo_ck CHECK (sexo in ("M", "F", "O", "m", "f", "o")), # enby alliance
	CONSTRAINT empregado_salario_ck CHECK (salario > 0)
);

CREATE TABLE departamento (
	numero INT NOT NULL,
	nome VARCHAR(20) NOT NULL,
	codigo_ger INT,
	data_inicio_ger DATE,

	CONSTRAINT depto_pk PRIMARY KEY (numero),
	CONSTRAINT depto_nome_uk UNIQUE (nome)
);

ALTER TABLE empregado
	ADD CONSTRAINT EMP_DEP_FK FOREIGN KEY (depto_num) REFERENCES departamento(numero); 