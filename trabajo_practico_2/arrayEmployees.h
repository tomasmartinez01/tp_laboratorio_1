#define FREE 1
#define TAKEN 0
#define LEN_EMP 1000
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief Initialize all the flags (isEmpty) in true
 *
 * \param listEmployees sEmployee array of employees
 * \param len int array length
 * \return int  Return (-1) if Error - (0) if Ok
 *
 */
int initEmployees(sEmployee listEmployees[], int len);
/** \brief load the information about an employee
 *
 * \param listEmployees sEmployee array of employees
 * \return sEmployee data set of employee
 *
 */
sEmployee setEmployee(sEmployee listEmployees[]);

/** \brief find free slot in flag(isEmpty)
 *
 * \param listEmployees[] sEmployee array of employees
 * \param len int array length
 * \return int index of free slot
 *
 */
int findFreeSlot(sEmployee listEmployees[], int len);
/** \brief add a employee in array of employee
 *
 * \param listEmployees[] sEmployee array of employees
 * \return int return (-1) if error, (0) if ok
 *
 */
int addEmployee(sEmployee listEmployees[]);

/** \brief find the next id for employee
 *
 * \param listEmployee[] sEmployee array of employees
 * \param len int array length
 * \return int value of next id
 *
 */
int nextId(sEmployee listEmployee[],int len);

/** \brief modify information about an employee
 *
 * \param listEmployees[] sEmployee array of employee
 * \return int (-1) if error, (0) if ok
 *
 */
int modifyEmployee(sEmployee listEmployees[]);

/** \brief print information about one employee
 *
 * \param listEmployees[] sEmployee array of employees
 * \param index int position of employee
 * \return void
 *
 */
void printAnEmployee(sEmployee listEmployees[], int index);

/** \brief print employees array
 *
 * \param listEmployees[] sEmployee array of employees
 * \param len int array length
 * \return void
 *
 */
void printEmployees(sEmployee listEmployees[], int len);

/** \brief find an employee by id and returns the position in array
 *
 * \param listEmployee[] sEmployee array of employees
 * \param len int array length
 * \param id int id to search
 * \return int (-1) if error or employee index position
 *
 */
int findEmployeeById(sEmployee listEmployee[], int len, int id);

/** \brief menu to modify information of employee
 *
 * \param listEmployee[] sEmployee array of employee
 * \param position int position of employee
 * \return void
 *
 */
void modifyMenu(sEmployee listEmployee[], int position);

/** \brief modify name of employee
 *
 * \param listEmployee[] sEmployee array of employee
 * \param position int position of employee
 * \return void
 *
 */
void modifyName(sEmployee listEmployee[], int position);

/** \brief modify last name of employee
 *
 * \param listEmployee[] sEmployee array of employee
 * \param position int position of employee
 * \return void
 *
 */
void modifyLastName(sEmployee listEmployee[], int position);

/** \brief modify salary of employee
 *
 * \param listEmployee[] sEmployee array of employee
 * \param position int position of employee
 * \return void
 *
 */
void modifySalary(sEmployee listEmployee[], int position);

/** \brief modify sector of employee
 *
 * \param listEmployee[] sEmployee array of employee
 * \param position int position of employee
 * \return void
 *
 */
void modifySector(sEmployee listEmployee[], int position);

/** \brief  Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param listEmployee[] sEmployee array of employee
 * \param len int array length
 * \return int (-1) if error, (0) if ok
 *
 */
int removeEmployee(sEmployee listEmployee[], int len);

/** \brief  Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param listEmployees[] sEmployee array of employees
 * \param len int array length
 * \param order int [1] indicate UP, [0] indicate DOWN
 * \return int (-1) if error, (0) if ok
 *
 */
int sortEmployees(sEmployee listEmployees[], int len, int order);

/** \brief menu for select if want up or down sort
 *
 * \param listEmplyees[] sEmployee array of employees
 * \param len int array length
 * \return void
 *
 */
void sortMenu(sEmployee listEmplyees[], int len);

/** \brief menu for inform case
 *
 * \param listEmployees[] sEmployee array of employees
 * \param len int array length
 * \return void
 *
 */
void infoMenu(sEmployee listEmployees[], int len);

/** \brief down order employees
 *
 * \param listEmployees[] sEmployee array of emmployees
 * \param len int array length
 * \return void
 *
 */
void sortDown(sEmployee listEmployees[], int len);

/** \brief up order employees
 *
 * \param listEmployees[] sEmployee array of emmployees
 * \param len int array length
 * \return void
 *
 */
void sortUp(sEmployee listEmployees[], int len);

/** \brief calculate total and average salary, and how many employees exceeds average salary
 *
 * \param listEmployee[] sEmployee array of employees
 * \param len int array length
 * \return void
 *
 */
void salaryInfo(sEmployee listEmployee[], int len);
/** \brief initialize ABM of employees
 *
 * \param void
 * \return void
 *
 */
void abmEmployees(void);
