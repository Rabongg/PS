select I.ANIMAL_ID, I.NAME, if(I.SEX_UPON_INTAKE like "%intact%", 'X', 'O') isNeutered
from ANIMAL_INS as I
order by I.ANIMAL_ID asc