/*João Antonio Araújo e Souza*/
CREATE DATABASE IF NOT EXISTS trabalho_final;

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS departamento (
	codigo INT NOT NULL,
	nome VARCHAR(100),

	PRIMARY KEY (codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS empregado (
	codigo INT NOT NULL,
	nome VARCHAR(200),
	cpf VARCHAR(14),
	tipo_de_empregado VARCHAR(100),
	FK_dep INT NOT NULL,

	PRIMARY KEY (codigo),
	FOREIGN KEY (FK_dep) REFERENCES departamento(codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS secretario (
	FK_codigo INT NOT NULL,

	FOREIGN KEY (FK_codigo) REFERENCES empregado(codigo),
	PRIMARY KEY (FK_codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS processador_de_texto (
	codigo INT NOT NULL,
	nome VARCHAR(100),

	PRIMARY KEY (codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS secretario_domina_processador (
	FK_codigo_secretario INT NOT NULL,
	FK_codigo_processador INT NOT NULL,

	FOREIGN KEY (FK_codigo_secretario) REFERENCES secretario(FK_codigo),
	FOREIGN KEY (FK_codigo_processador) REFERENCES processador_de_texto(codigo),
	PRIMARY KEY (FK_codigo_processador, FK_codigo_secretario)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS motorista (
	FK_codigo INT NOT NULL,
	carteira_habilitacao VARCHAR(11),

	FOREIGN KEY (FK_codigo) REFERENCES empregado(codigo),
	PRIMARY KEY (FK_codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS ramo_da_engenharia (
	codigo INT NOT NULL,
	nome VARCHAR(100),

	PRIMARY KEY (codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS engenheiro (
	FK_codigo INT NOT NULL,
	crea VARCHAR(8),
	FK_ramo_engenharia INT NOT NULL,

	FOREIGN KEY (FK_codigo) REFERENCES empregado(codigo),
	FOREIGN KEY (FK_ramo_engenharia) REFERENCES ramo_da_engenharia(codigo),
	PRIMARY KEY (FK_codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS projeto (
	codigo INT NOT NULL,
	nome VARCHAR(100),

	PRIMARY KEY (codigo)
);

/*João Antonio Araújo e Souza*/
CREATE TABLE IF NOT EXISTS engenheiro_participa_projeto (
	FK_codigo_engenheiro INT NOT NULL,
	FK_codigo_projeto INT NOT NULL,

	FOREIGN KEY (FK_codigo_engenheiro) REFERENCES engenheiro(FK_codigo),
	FOREIGN KEY (FK_codigo_projeto) REFERENCES projeto(codigo),
	PRIMARY KEY (FK_codigo_engenheiro, FK_codigo_projeto)
);