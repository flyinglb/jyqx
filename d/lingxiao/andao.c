//LUCAS 2000-6-18

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�������ǵİ�������������������ʲô�˳��������
ͨ������ǽ�ϲ��ŵļ��������ɢ�����Ĺ�â�£����Կ�������
��һ���飬��֪�����ĸ����Ĺ��������ġ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "out"  : __DIR__"muwu",
            "northdown"  : __DIR__"didi",
        ]));
        set("objects", ([
                __DIR__"obj/swordbook" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

