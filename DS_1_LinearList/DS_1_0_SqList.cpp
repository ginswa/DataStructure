//
// Created by kim on 2020/6/17.
// Copyright (c) Kim Yang All rights reserved.
//

//˳�������̬�����ʵ�ַ�ʽ

/**����ģ��**/

#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//��������
void InitList(SqList &L);                           //��ʼ��
bool Empty(SqList L);                               //�п�
bool ListInsert(SqList &L, int i, int e);           //����
bool ListDelete(SqList &L, int i, int &e);          //ɾ��
int GetElem(SqList L, int i);                       //��λ����
int LocateElem(SqList L, int e);                    //��ֵ����
bool LocateChangeElem(SqList &L, int e, int em);    //��ֵ�޸�
bool getChangeElem(SqList &L, int i, int em);       //��λ�޸�

void PrintSqList(SqList L);                         //��ӡ����
void testModule();                                  //����ģ��

/**����ģ��**/

/**ʵ��ģ��**/

//��ʼ��
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;//������Ԫ�صĳ�ʼֵĬ������Ϊ0
        //��һ����ʵ����ʡ�ԣ�����ʡ��֮���п����ܵ��ڴ���"������"��Ӱ��
    }
    L.length = 0;

}

//�п�
bool Empty(SqList L) {
    return (L.length == 0);
}

//����
bool ListInsert(SqList &L, int i, int e) {
    //�жϲ����λ���Ƿ�Ϸ���
    if (i < 1 || i > L.length + 1)
        return false;
    //�жϱ��Ƿ������
    if (L.length >= MaxSize)
        return false;

    //�����Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//ɾ��
bool ListDelete(SqList &L, int i, int &e) {
    //�ж�i��λ���Ƿ�Ϸ�
    if (i < 0 || i > L.length) {
        return false;
    }
    //ȡ����Ҫ��ɾ������
    e = L.data[i - 1];
    //����������ǰ��
    for (int j = i; j <= L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    //���Ա��ȼ�һ
    L.length--;
    return true;
}

//����
//��λ����
int GetElem(SqList L, int i) {
    //�ж��Ƿ�Խ��
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}

//��ֵ����
int LocateElem(SqList L, int e) {
    //ѭ��������
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //����λ��
    }
    return -1;
}

//��
//�Ȳ��Һ��ֵ
//�ɴ˷�Ϊ���ַ�ʽ���Ȱ�λ���Һ��ֵ�����Ȱ�ֵ���Һ��ֵ
//�Ȱ�ֵ���Һ��ֵ
bool LocateChangeElem(SqList &L, int e, int em) {
    //��ֵ���ҵõ�λ��
    int bitOrder = LocateElem(L, e);
    //��ֵ
    if (bitOrder != -1) {
        L.data[bitOrder] = em;
        return true;
    } else {
        return false;
    }
}

//�Ȱ�λ����Һ��ֵ
bool getChangeElem(SqList &L, int i, int em) {
    //ע�������Ǹ�ֵ�漰�޸�ԭ���ݣ�������Ҫ�����ô��ݵķ�ʽ
    //����λ��,�����ж�i�Ƿ�Ϸ�
    if (i < 0 || i >= L.length)return false;

    //������������ʵ�ֵķ�ʽ������ֱ������i����
    L.data[i] = em;
    return true;

}


//����
//���ھ�̬���䷽ʽ��ͨ����������ķ�ʽʵ�ֵģ��ʲ���Ҫ�ֶ�����SqList����ʹ�����֮��ϵͳ���Զ�ɾ�����ݲ��������ݿռ�

/**ʵ��ģ��**/

/**����ģ��**/

//����
//��ӡ����˳���
void PrintSqList(SqList L) {
    //ѭ����ӡ
    printf("��ʼ��ӡ˳���\n");
    for (int i = 0; i < L.length; i++) {
        printf("Data[%d]==%d\n", i, L.data[i]);
    }
    printf("��ӡ������\n");
}

//���Ժ���
void testModule() {
    SqList L;
    InitList(L);

//    ���Ի�һЩֵ
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    //�������
    if (ListInsert(L, 2, 3)) {
        printf("����ɹ���\n");
    } else {
        printf("����ʧ���ˣ�i��λ�ò��Ϸ�������\n");
    }

    //ɾ������
    int e = -1;
    if (ListDelete(L, 2, e)) {
        printf("ɾ���ɹ���ɾ����ֵ�ǣ�%d\n", e);
    } else {
        printf("ɾ��ʧ�ܣ�����λ���Ƿ���ȷ\n");
    }

    //���鵱ǰ����
    printf("���鵱ǰ�����Ƕ��٣�%d\n", L.length);

    //���ҵ�һ��Ԫ����ʲô��
    printf("��һ��Ԫ����ʲô��\n %d\n", GetElem(L, 1));

    //����ֵΪ3��Ԫ����ʲôλ��
    printf("��һ��ֵΪ3��Ԫ����ʲôλ�ã�\n %d \n", LocateElem(L, 3));

    //��ӡ���
    PrintSqList(L);

    //���Ը�ģ�鹦���Ƿ�����
    int e1 = 2;
    int em1 = 6;
    int i = 1;
    int em2 = 7;
    printf("��ʼ���ԡ��ġ�\n"
           "��һ�ַ�ʽ�Ȱ�ֵ���Һ��ֵ\n");
    if (LocateChangeElem(L, e1, em1)) {
        printf("��һ���Ȱ�ֵ���Һ��ֵ�ɹ������ı���ֵ���£�\n");
        PrintSqList(L);
    } else {
        printf("��һ���Ȱ�ֵ���Һ��ֵʧ���ˣ��ټ��һ�°ɣ�\n");
    }
    printf("�ڶ����Ȱ�λ����Һ��ֵ\n");
    if (getChangeElem(L, i, em2)) {
        printf("�ڶ����Ȱ�λ����Һ��ֵ�ķ�ʽ�ɹ������ı���ֵ���£�\n");
        PrintSqList(L);
    } else {
        printf("�ڶ����Ȱ�λ����Һ��ֵ�ķ�ʽʧ���ˣ��ټ��һ�°ɣ�\n");
    }
    if (Empty(L)) {
        printf("˳���Ϊ�գ�\n");
    } else {
        printf("˳���ǿգ�\n");
    }

    //��ӡ���
    PrintSqList(L);
}
/**����ģ��**/
//������
int main() {
    testModule();
    return 0;
}