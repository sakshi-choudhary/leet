# Write your MySQL query statement below
select Department.name as Department, 
Employee.name as Employee, 
Salary from Employee 
join Department 
on 
Employee.DepartmentId = Department.Id 
where (departmentId, Salary) in (select departmentId,max(salary) from Employee group by departmentId);
