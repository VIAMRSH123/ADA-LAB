int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int queueStart = 0, queueEnd = studentsSize - 1;
    int served = 0, attempts = 0;

    while (served < studentsSize && attempts < studentsSize) {
        if (students[queueStart] == sandwiches[served]) {
            served++;
            queueStart = (queueStart + 1) % studentsSize;
            attempts = 0;
        } else {
            queueEnd = (queueEnd + 1) % studentsSize;
            students[queueEnd] = students[queueStart];
            queueStart = (queueStart + 1) % studentsSize;
            attempts++;
        }
    }

    return studentsSize - served;
}
