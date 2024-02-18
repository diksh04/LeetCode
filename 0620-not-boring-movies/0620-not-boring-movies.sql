# Write your MySQL query statement below
select * from Cinema where MOD(id,2)=1 AND description <> 'boring' order by rating desc;