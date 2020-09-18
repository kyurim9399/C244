//kyurim kim	168819183	kkim125@myseneca.com
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream> 

namespace sdds {
	class Employee {
	public:
		virtual ~Employee() {};
		virtual void setSalary(double) = 0;
		//이 기능은 직원의 급여를 설정합니다
		virtual void bonus() = 0;
		//이 기능은 직원의 보너스를 계산합니다
		virtual bool workHours() const = 0;
		//직원이 최소 시간 동안 작업하는 경우 true를 반환하는 쿼리입니다.
		virtual std::ostream& display(std::ostream& os) const = 0;
		//이 기능은 직원에 대한 세부 사항을 표시합니다.
	};
}
#endif