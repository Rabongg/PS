set @hour := -1;

select (@hour := @hour + 1) as HOUR,
(select count(animal_id) from animal_outs where hour(datetime) = @hour) as COUNT
from animal_outs
where @hour < 23