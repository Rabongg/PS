-- 코드를 입력하세요
SELECT I.ANIMAL_ID, I.NAME
from ANIMAL_INS as I join ANIMAL_OUTS as O
on I.ANIMAL_ID = O.ANIMAL_ID
order by datediff(O.datetime,I.datetime) desc
limit 2