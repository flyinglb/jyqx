//LUCAS 2000-6-18
// Room: wave2.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
��������һ��������������������������Ȼ����͸�����ڿ�
�����������Ⱥɽ��ԭ���������ǽ���������ϵı��㣬�¹���
���������յ��������ԣ������������������𡮱��������β��ɣ�
������ˮҹ���ᡯ���⾳��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "enter"  : __DIR__"wave", 
            "east" : __DIR__"wave1", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

