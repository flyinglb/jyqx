//LUCAS 2000-6-18
// Room: huajing.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�������˸�ɫ÷���Ļ�����С�����ߣ�÷��Ʈ�㣬÷
����������Ȼ���ͼ���÷֦���ѣ�÷����᫣�����Ʈ�ݣ������
֮��÷��֦���Կݲг�׾Ϊ��÷��÷���Է���Ũ��Ϊ�У��˴�
֮������ν���ӡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"qianyuan",
            "up"  : __DIR__"feihua",  
        ]));
        set("objects", ([
               "/d/lingxiao/npc/xuehe" : 1,
               "/d/lingxiao/obj/mei" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

