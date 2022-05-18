-- 코드를 입력하세요
select HOUR(datetime) HOUR, count(datetime) COUNT 
from animal_outs 
group by HOUR(datetime) 
having 8 < HOUR and HOUR < 20 
order by HOUR ASC