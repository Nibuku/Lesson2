#include <gtest/gtest.h>
#include <lesson/lesson.h>
using namespace std;

TEST(LessonTests, LabTest1) {
    Lesson lesson(LessonType::LAB, Name::OOP, 5);
    int r = lesson.compute_paid_hours(4, 8);
    EXPECT_EQ(r, 40);
}


TEST(LessonTests, LectureTest1) {
    Lesson lesson(LessonType::LECTURE, Name::OOP, 5);
    int r = lesson.compute_paid_hours(4, 8);
    EXPECT_EQ(r, 5);
}

TEST(LessonTests, PracticeTest1) {
    // Arrange
    Lesson lesson(LessonType::PRACTICE, Name::OOP, 5);

    // Act
    int r = lesson.compute_paid_hours(4, 8);

    // Assert
    EXPECT_EQ(r, 20);
}

TEST(LessonTests, ForGetName) {
    // Arrange
    Lesson lesson(LessonType::PRACTICE, Name::OOP, 5);

    // Act
    int r = lesson.getName();

    // Assert
    EXPECT_EQ(r, OOP);
}
TEST(LessonTests, ForGetHours) {
    // Arrange
    Lesson lesson(PRACTICE, Name::ALGEBRA, 5);

    // Act
    int r = lesson.gethours();

    // Assert
    EXPECT_EQ(r, 5);
}
TEST(LessonTests, ForGetType) {
    // Arrange
    Lesson lesson(PRACTICE, Name::ALGEBRA, 5);

    // Act
    int r = lesson.getLessonType();

    // Assert
    EXPECT_EQ(r, PRACTICE);
}
TEST(LessonTests, GetType) {
    // Arrange
    Lesson lesson(LAB, Name::ALGEBRA, 5);

    // Act
    int r = lesson.getLessonType();

    // Assert
    EXPECT_EQ(r, LAB);
}
TEST(LessonTests, SetType) {
    Lesson lesson;
    lesson.setLessonType(PRACTICE);
    EXPECT_EQ(lesson.getLessonType(), PRACTICE);
}
TEST(LessonTests, SetName) {
    Lesson lesson;
    lesson.setName(OOP);
    EXPECT_EQ(lesson.getName(), OOP);
}
TEST(LessonTests, Sethours) {
    Lesson lesson;
    lesson.sethours(12);
    EXPECT_EQ(lesson.gethours(), 12);
}
TEST(LessonTests, Compute1Sum) {
    LessonList lesson= LessonList();
    EXPECT_EQ(lesson.compute_sum(lesson, 4, 8, OOP),0 );
}

TEST(LessonListTests, LessonListDefaultConstructorTest) {
    LessonList ll = LessonList();
    EXPECT_EQ(ll.size(), 5);
}

TEST(LessonListTests, LessonListInsertTest) {
    LessonList ll = LessonList();
    Lesson one = Lesson(LAB, OOP, 8);
    ll.insert(1, one);
    EXPECT_EQ(ll.size(), 6);
    EXPECT_EQ(ll[1]->getLessonType(), LAB);
    EXPECT_EQ(ll[1]->getName(), OOP);
    EXPECT_EQ(ll[1]->gethours(), 8);
}

TEST(LessonListTests, LessonListRemoveTest) {
    LessonList ll = LessonList();
    ll.remove(0);
    EXPECT_EQ(ll.size(), 4);
}

TEST(LessonListTests, LessonListMaxComputeTest) {
    LessonList ll;
    LessonPtr lesson = new Lesson[5];
    ll.insert(0, lesson[0] = Lesson(LAB, OOP, 3));
    ll.insert(0, lesson[1] = Lesson(LAB, OOP, 3));
    ll.insert(0, lesson[2] = Lesson(LECTURE, GEOMETRIYA, 3));
    ll.insert(0, lesson[3] = Lesson(PRACTICE, ALGEBRA, 2));
    EXPECT_EQ(ll.compute_max_paid(ll, 2, 4), 0);
    delete[] lesson;
}


TEST(lessonTests, LessonIndexOutTest) {
    LessonList ll = LessonList();
    EXPECT_THROW(ll.remove(-1), std::runtime_error);
    EXPECT_THROW(ll.remove(10), std::runtime_error);
}

TEST(LessonListTests, LessonListCtorAndOPCpyTest) {
  
    LessonList EL = LessonList();
    LessonList EL2(EL);
    LessonList EL3 = EL;
    EXPECT_EQ(EL, EL2);
    EXPECT_EQ(EL, EL3);
}