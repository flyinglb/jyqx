//LUCAS 2000-6-18
// Room: fudian1.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�����������ǵĸ���֮һ������������������һ����ͷ��
�Եز�֪�ڸ�ʲô���������ģ�׼ûʲô���¡������������
��̫ƽ���鷳����Ҳͦ��ģ���������Ϊ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"lianwu2",
            "west"  : __DIR__"dadian",
        ]));
        set("objects", ([
               "/d/lingxiao/npc/dizi" : 3,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

