// husun.c

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨�ϣ���˵��
ǰ�ӻ�ɽˮ����������Գ�ÿ�������Ҫ����ȥ��������Ҳ�е����ڳ�
Խ���������������
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "northdown" : __DIR__"laojun",
            "southup"   : __DIR__"shangtianti",
        ]));
        set("objects", ([ /* sizeof() == 2 */
            "/d/wudang/npc/monkey": 1,
            "/d/wudang/npc/little_monkey": 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
