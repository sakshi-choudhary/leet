# Write your MySQL query statement below
select c.name AS 'Customers' from Customers c left join Orders o on c.id=o.CustomerId where o.CustomerId IS NULL;