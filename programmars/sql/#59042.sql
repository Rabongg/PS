-- 코드를 입력하세요
SELECT animal_outs.animal_id, animal_outs.name 
from animal_ins 
right outer join animal_outs 
on animal_ins.animal_id = animal_outs.animal_id 
where animal_ins.animal_id is null
order by animal_outs.animal_id ASC


/* 
SELECT ANIMAL_ID, NAME
FROM ANIMAL_OUTS
WHERE NOT EXISTS (
  SELECT ANIMAL_INS.ANIMAL_ID
  FROM ANIMAL_INS
  WHERE ANIMAL_OUTS.ANIMAL_ID = ANIMAL_INS.ANIMAL_ID
)
 */