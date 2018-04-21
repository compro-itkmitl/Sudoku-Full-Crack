#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

using SudokuGrid = std::array<std::array<QPushButton*, 9>, 9>;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void pushButtonPressed(QPushButton *pushButton, int row, int col);
    void controlButtonPressed(QPushButton *pushButton, int num);
    void on_allStepButton_clicked();
    void on_listWidget_itemDoubleClicked();
    void on_clearButton_clicked();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    int grid_edit[9][9];
    int **grid_edited;
    int **grid_locked;
    int **grid_step;
    int grid_setNum;
    SudokuGrid buttonGrid;
    int onlyGetStepRound;
    int is_clickedAllStep;
    int is_inValid;
    int is_noSolution;

    QPushButton* getControlButton(int num);
    void setButtonNum(QPushButton *pushButton, int num, int size, bool onlyHover);
    SudokuGrid initButtonGrid();
    void gridCandidate(int loopFreeze);
    void selectGridCandidate(int index);

};

#endif // MAINWINDOW_H
