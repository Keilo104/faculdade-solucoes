/*João Antonio Araújo e Souza*/
SELECT 
	COUNT(DISTINCT l1.id) as 'Qtde Lutador',
	COUNT(DISTINCT c.id) as 'Qtde Cenarios',
	COUNT(DISTINCT m.id) as 'Qtde Mundos',
	COUNT(DISTINCT l2.id) as 'Qtde Lutas'
FROM lutador l1
JOIN cenario c
JOIN mundo m
JOIN luta l2

/*João Antonio Araújo e Souza*/
SELECT
	l.nome as 'Lutador',
	c.nome as 'Cenario',
	m.nome as 'Mundo'
FROM lutador_tem_cenario lc
JOIN lutador l ON lc.lutador_id = l.id
JOIN cenario c ON lc.cenario_id = c.id
JOIN mundo m ON c.mundo_id = m.id
ORDER BY l.nome ASC

/*João Antonio Araújo e Souza*/
SELECT
	l.nome as 'Lutador',
	c.nome as 'Cenario',
	m1.nome as 'Mundo',
	m2.nome as 'Mundo Origem'
FROM lutador_tem_cenario lc
JOIN lutador l ON lc.lutador_id = l.id
JOIN cenario c ON lc.cenario_id = c.id
JOIN mundo m1 ON c.mundo_id = m1.id
JOIN mundo m2 ON l.mundo_id = m2.id
WHERE l.mundo_id != c.mundo_id
ORDER BY l.nome ASC

/*João Antonio Araújo e Souza*/
SELECT
	l1.id as "id-P1",
	l1.nome as "P1",
	l2.id as "id-P2",
	l2.nome as "P2",
	c.nome as "Cenario",
	luta.data as "Data",
	v.nome as "Vencedor"
FROM luta luta
JOIN lutador l1 ON luta.lutador_id1 = l1.id
JOIN lutador l2 ON luta.lutador_id2 = l2.id
JOIN lutador v ON luta.vencedor_id = v.id
JOIN cenario c ON luta.cenario_id = c.id
ORDER BY luta.data ASC

/*João Antonio Araújo e Souza*/
SELECT
	l.nome as "Lutador",
	COUNT(v.vencedor_id) as "Vitórias"
FROM lutador l
JOIN luta v ON v.vencedor_id = l.id
GROUP BY v.vencedor_id
ORDER BY COUNT(v.vencedor_id) DESC

/*João Antonio Araújo e Souza*/
SELECT
	l.nome as "Lutador",
	COUNT(v.id) as "Vitórias"
FROM luta v
JOIN lutador l ON v.vencedor_id = l.id
WHERE v.vencedor_id in (SELECT lutador_id FROM lutador_tem_cenario WHERE cenario_id = v.cenario_id)
GROUP BY v.vencedor_id
ORDER BY COUNT(v.vencedor_id) DESC

