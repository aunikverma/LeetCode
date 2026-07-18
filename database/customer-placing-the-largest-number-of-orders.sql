# Write your MySQL query statement below
select customer_number from Orders group by customer_number order by count(order_number) desc limit 1;
#we group according to customer_number sort according to count using desc and pick first one using limit