-- 코드를 입력하세요
select I.ANIMAL_ID, I.ANIMAL_TYPE, I.NAME
from ANIMAL_INS as I join ANIMAL_OUTS as O
on I.ANIMAL_ID = O.ANIMAL_ID
where I.SEX_UPON_INTAKE like "%Intact%"
and O.SEX_UPON_OUTCOME not like "%Intact%"
order by I.ANIMAL_ID asc