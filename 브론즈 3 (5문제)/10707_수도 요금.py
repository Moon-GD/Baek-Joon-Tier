x_standard = int(input())
y_standard = int(input())
y_upper_bound = int(input())
y_surcharge = int(input())
usage = int(input())

x_fare = x_standard * usage

# 상한 사용량 초과한 경우
if usage > y_upper_bound:
    y_fare = y_standard + y_surcharge * (usage - y_upper_bound)
# 기본 요금만 발생하는 경우
else:
    y_fare = y_standard

print(min(x_fare, y_fare))
