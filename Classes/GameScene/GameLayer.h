//
//  GameLayer.h
//  AITetris
//
//  Created by yangjh on 15/4/28.
//
//

#ifndef __AITetris__GameLayer__
#define __AITetris__GameLayer__

#include <stdio.h>
#include "Tetris.h"
#include "TetrisAI.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameLayer);
    
    void startGame();
    void startAI(bool AIOn);
    void accelerateAI();
    void decelerateAI();
    float getAISpeed() { return 1/m_speedAI; }
    // 方块操作
    void moveLeftBrick();
    void moveRightBrick();
    void rotateBrick();
    void fallBrick();
    void throwDownBrick();
    
private:
    // 刷新方块矩阵
    void updateTetrisBrickMatrix();
    // 在log中显示游戏
    void showTetrisInLog();
    // 执行AI系统返回的操作列表
    void commitOperationList(int index);
    
private:
    // Tetris逻辑
    Tetris *m_tetris;
    bool m_gameRun;
    // 精灵方块，用于方块矩阵的展现
    const int Row_Tetris = 21;
    const int Column_Tetris = 12;
    Sprite **m_spriteBrick;
    // AI操作
    float m_speedAI;
    Action *m_actionAI;
    OperationType m_operationList[3+12/2+1];
};

#endif /* defined(__AITetris__GameLayer__) */
