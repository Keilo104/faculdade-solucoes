/*João Antonio Araújo e Souza*/
ALTER TABLE empregado
ADD salario INT;

/*João Antonio Araújo e Souza*/
UPDATE empregado
SET salario = CASE codigo
	WHEN 1 THEN 6691
	WHEN 2 THEN 8731
	WHEN 3 THEN 3165
	WHEN 4 THEN 5994
	WHEN 5 THEN 1380
	WHEN 6 THEN 7420
	WHEN 7 THEN 5006
	WHEN 8 THEN 5513
	WHEN 9 THEN 2220
	WHEN 10 THEN 5822
	WHEN 11 THEN 7522
	WHEN 12 THEN 2451
	WHEN 13 THEN 4474
	WHEN 14 THEN 1780
	WHEN 15 THEN 2204
	WHEN 16 THEN 8186
	WHEN 17 THEN 6810
ELSE salario END

/*João Antonio Araújo e Souza*/
SELECT * FROM empregado ORDER BY salario DESC

/*João Antonio Araújo e Souza*/
SELECT 
	e.cpf,
	e.nome as 'motorista',
	e.salario,
	m.carteira_habilitacao
FROM 
	motorista m
JOIN empregado e ON m.FK_codigo = e.codigo

/*João Antonio Araújo e Souza*/
SELECT
	emp.nome,
	emp.salario,
	eng.crea,
	ramo.nome as 'ramo de atuação'
FROM
	engenheiro eng
JOIN empregado emp ON eng.FK_codigo = emp.codigo
JOIN ramo_da_engenharia ramo ON eng.FK_ramo_engenharia = ramo.codigo
WHERE eng.FK_codigo NOT IN (SELECT DISTINCT FK_codigo_engenheiro FROM engenheiro_participa_projeto)

/*João Antonio Araújo e Souza*/
ALTER TABLE secretario
ADD login VARCHAR(200);

/*João Antonio Araújo e Souza*/
UPDATE secretario
SET login = CASE FK_codigo
	WHEN 5 THEN 'UtopianAbigayle'
	WHEN 6 THEN 'EmillieOfLila'
	WHEN 7 THEN 'VanFriedman'
	WHEN 8 THEN 'VictoriousQuintana'
	WHEN 9 THEN 'ZaoElyas'
ELSE login END

/*João Antonio Araújo e Souza*/
SELECT
	e.cpf,
	e.nome as 'NomeFunc',
	e.salario,
	s.login,
	p.nome as 'NomeProc'
FROM
	secretario_domina_processador sp
JOIN secretario s ON sp.FK_codigo_secretario = s.FK_codigo
JOIN empregado e ON s.FK_codigo = e.codigo
JOIN processador_de_texto p ON sp.FK_codigo_processador = p.codigo

/*João Antonio Araújo e Souza*/
SELECT * FROM empregado
WHERE
	codigo NOT IN (SELECT DISTINCT FK_codigo FROM secretario) AND
	codigo NOT IN (SELECT DISTINCT FK_codigo FROM motorista) AND
	codigo NOT IN (SELECT DISTINCT FK_codigo FROM engenheiro)

/*João Antonio Araújo e Souza*/
SELECT * FROM empregado
WHERE tipo_de_empregado IS NULL

/*João Antonio Araújo e Souza*/
SELECT 
	emp.nome,
	emp.cpf,
	emp.salario,
	e.crea,
	p.nome
FROM engenheiro e
INNER JOIN engenheiro_participa_projeto ep ON e.FK_codigo = ep.FK_codigo_engenheiro
JOIN projeto p ON p.codigo = ep.FK_codigo_projeto
JOIN empregado emp ON emp.codigo = e.FK_codigo

/*João Antonio Araújo e Souza*/
SELECT
	emp.nome,
	emp.cpf,
	emp.salario,
	p.nome
FROM secretario s
LEFT OUTER JOIN secretario_domina_processador sp ON sp.FK_codigo_secretario = s.FK_codigo
LEFT OUTER JOIN processador_de_texto p ON p.codigo = sp.FK_codigo_processador
JOIN empregado emp ON s.FK_codigo = emp.codigo

/*João Antonio Araújo e Souza*/
SELECT
	emp.nome,
	p.nome
FROM engenheiro eng
RIGHT OUTER JOIN engenheiro_participa_projeto ep ON ep.FK_codigo_engenheiro = eng.FK_codigo
RIGHT OUTER JOIN projeto p ON p.codigo = ep.FK_codigo_projeto
JOIN empregado emp ON eng.FK_codigo = emp.codigo

/*João Antonio Araújo e Souza*/
SELECT *
FROM empregado emp
WHERE emp.codigo IN (SELECT DISTINCT m.FK_codigo FROM motorista m)

/*João Antonio Araújo e Souza*/
SELECT *
FROM empregado emp
WHERE emp.salario > ANY (
		SELECT e.salario
		FROM secretario s
		JOIN empregado e ON e.codigo = s.FK_codigo
		)

/*João Antonio Araújo e Souza*/
SELECT *
FROM empregado emp
WHERE emp.salario > ALL (
		SELECT e.salario
		FROM engenheiro eng
		JOIN empregado e ON e.codigo = eng.FK_codigo
		)

/*João Antonio Araújo e Souza*/
SELECT COUNT(*) as "quantidade"
FROM empregado e
WHERE e.tipo_de_empregado IS NULL

/*João Antonio Araújo e Souza*/
SELECT SUM(salario) as "soma salário"
FROM empregado e
WHERE e.tipo_de_empregado = "secretario"

/*João Antonio Araújo e Souza*/
SELECT AVG(salario) as "média salário"
FROM empregado e

/*João Antonio Araújo e Souza*/
SELECT MAX(salario) as "maior salário"
FROM empregado e

/*João Antonio Araújo e Souza*/
SELECT MIN(salario) as "menor salário"
FROM empregado e
WHERE e.tipo_de_empregado = "motorista"

/*João Antonio Araújo e Souza*/
SELECT 
	p.nome,
	emp1.salario,
	eng1.crea,
	emp1.cpf,
	emp1.nome
FROM projeto p
JOIN empregado emp1 ON emp1.salario = (
	SELECT MAX(emp2.salario)
	FROM engenheiro_participa_projeto ep
	JOIN engenheiro eng2 ON ep.FK_codigo_engenheiro = eng2.FK_codigo
	JOIN empregado emp2 ON eng2.FK_codigo = emp2.codigo
	WHERE ep.FK_codigo_projeto = p.codigo
	)
JOIN engenheiro eng1 ON emp1.codigo = eng1.FK_codigo

/*João Antonio Araújo e Souza*/
SELECT
	emp.nome,
	emp.cpf,
	eng.crea,
	emp.salario
FROM engenheiro eng
JOIN empregado emp ON eng.FK_codigo = emp.codigo
WHERE eng.FK_codigo IN (
	SELECT DISTINCT ep.FK_codigo_engenheiro
	FROM engenheiro_participa_projeto ep
)

/*João Antonio Araújo e Souza*/
SELECT
	d.nome,
	AVG(e.salario) as "média salário"
FROM departamento d
JOIN empregado e ON e.FK_dep = d.codigo
GROUP BY d.nome

/*João Antonio Araújo e Souza*/
SELECT
	d.nome,
	SUM(e.salario) as "total salários"
FROM departamento d
JOIN empregado e ON e.FK_dep = d.codigo
GROUP BY d.nome
HAVING SUM(e.salario) > 15000