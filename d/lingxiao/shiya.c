//LUCAS 2000-6-18
// Room: shiya.c

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
ת��ɽ����������ʯ�໥��������һ���ܷ��ʯ�¡���
��˷��������ȴ¯�����ܣ���ľ����������˿˿�������ζ��
��������Ѳɽ���ˣ���������ܷ������Ա��и�С�꣬ƣ�ۼ�
��ʱ����������������Ϣ��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "westdown"  : __DIR__"sroad3",
            "east"  : __DIR__"bar", 
            "northup"  : __DIR__"sroad4",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

