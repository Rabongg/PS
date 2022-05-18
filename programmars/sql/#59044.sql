select name, datetime
from ANIMAL_INS as I
where not exists (
    select O.NAME
    from ANIMAL_OUTS as O
    where O.ANIMAL_ID = I.ANIMAL_ID
)
order by I.datetime ASC
limit 3