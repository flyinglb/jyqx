//LUCAS 2000-6-18
// Room: iceroad1.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
������һƬ�������������硣����·�ϣ���ͷһ����·����
�����ز����ĺ������ƣ���Ө��͸�����ӳ�����˵��������
�ı��ϣ�Ӧ�û��ﲻ��������ϸһ����ÿ�������ϣ�������ϸϸ
�Ļ��ƣ�����������ϸ����Ȼ�ķ��˴���������
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"gate",
            "north"  : __DIR__"iceroad2",
            "west"  : __DIR__"hotel",
            "east"  : __DIR__"sell",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

