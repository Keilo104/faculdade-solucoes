/*João Antonio Araújo e Souza*/
INSERT INTO departamento (codigo, nome) VALUES
(1, 'Relações Humanas'),
(2, 'Tecnologia'),
(3, 'Entregas'),
(4, 'Maquinação'),
(5, 'Administração');

/*João Antonio Araújo e Souza*/
INSERT INTO empregado (codigo, nome, cpf, tipo_de_empregado, FK_dep) VALUES
(1, 'Eoin Sadler', '173.803.500-05', NULL, 1),
(2, 'Taha Wallace', '283.919.760-09', NULL, 5),
(3, 'Allana Perkins', '505.936.270-16', NULL, 2),
(4, 'Rogan Kearney', '543.146.480-90', NULL, 4),
(5, 'Abigayle Kirkpatrick', '739.803.390-76', 'secretario', 1),
(6, 'Emillie Drake', '146.908.910-60', 'secretario', 2),
(7, 'Naya Friedman', '413.145.510-27', 'secretario', 3),
(8, 'Amelie Quintana', '827.575.900-57', 'secretario', 1),
(9, 'Elyas Benitez', '312.710.300-04', 'secretario', 3),
(10, 'Emilie Keller', '973.092.170-98', 'motorista', 3),
(11, 'Shakil Butt', '166.583.890-63', 'motorista', 5),
(12, 'Fionnuala Curry', '581.830.490-60', 'motorista', 2),
(13, 'Sumaya Saunders', '483.147.850-40', 'engenheiro', 4),
(14, 'Lina Werner', '076.320.980-54', 'engenheiro', 4),
(15, 'Rochelle Oneil', '418.457.420-36', 'engenheiro', 1),
(16, 'Ruairi Hodges', '064.752.800-20', 'engenheiro', 1),
(17, 'Aayan Collier', '979.652.410-48', 'engenheiro', 4);

/*João Antonio Araújo e Souza*/
INSERT INTO ramo_da_engenharia (codigo, nome) VALUES
(1, 'Engenharia Ambiental'),
(2, 'Engenharia Civil'),
(3, 'Engenharia da Computação'),
(4, 'Engenharia de Controle e Automação'),
(5, 'Engenharia Elétrica'),
(6, 'Engenharia Mecânica');

/*João Antonio Araújo e Souza*/
INSERT INTO projeto (codigo, nome) VALUES
(1, 'Plano Inovação'),
(2, 'Grupo Conceito de Design'),
(3, 'Centauro Engenharia'),
(4, 'Óleo e Energia SA');

/*João Antonio Araújo e Souza*/
INSERT INTO processador_de_texto (codigo, nome) VALUES
(1, 'Word'),
(2, 'Excel'),
(3, 'PowerPoint'),
(4, 'OneNote');

/*João Antonio Araújo e Souza*/
INSERT INTO engenheiro (FK_codigo, crea, FK_ramo_engenharia) VALUES
(13, 'RS486363', 2),
(14, 'RS647332', 3),
(15, 'RS242601', 5),
(16, 'RS698092', 6),
(17, 'RS633790', 6);

/*João Antonio Araújo e Souza*/
INSERT INTO secretario (FK_codigo) VALUES
(5),
(6),
(7),
(8),
(9);

/*João Antonio Araújo e Souza*/
INSERT INTO motorista (FK_codigo, carteira_habilitacao) VALUES
(10, '35651658014'),
(11, '82119101424'),
(12, '85878571953');

/*João Antonio Araújo e Souza*/
INSERT INTO engenheiro_participa_projeto (FK_codigo_engenheiro, FK_codigo_projeto) VALUES
(16, 3),
(14, 2),
(13, 1),
(15, 2),
(14, 4),
(13, 4),
(15, 1);

/*João Antonio Araújo e Souza*/
INSERT INTO secretario_domina_processador (FK_codigo_secretario, FK_codigo_processador) VALUES
(7, 1),
(6, 4),
(8, 1),
(5, 2),
(5, 3),
(5, 4),
(8, 2);