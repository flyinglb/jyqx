 // chengxiang.c

inherit ROOM;

void create()
{
        set("short", "������ɽ��");
        set("long", @LONG
��˵��ɽ��ʥĸ������һ�������������������Ϊ�򸾣����ֶ�����
�������ǽ�ϣ�����ѹ�ڻ�ɽ�£����Ķ��ӳ��㳤����ø���������ɽ��
�ȳ���ĸ�ס��Ա���һ���м��ѿ��Ĵ�ʯ�����ø���������һ�㣬������
��ʯ����˵���ǳ�����ɽ��ĸ�ĵط���
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "westup"   : __DIR__"lianhua",
            "eastdown" : __DIR__"lianpath2",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
