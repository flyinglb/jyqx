// Room: /d/village/shack.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
����һ���򵥵Ĳ�����ϰ���һ�ѶѵĻ����ɽ���οͿ�������
��Щ��ɽ��Ʒ�������ǽ�����Ÿ����ӣ��Ǹ���Ŀ��(sign)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"eroad1",
        ]));
        set("objects", ([
                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ /* sizeof() == 1 */
        "sign" : "������д����
	����(stick)	һ����
	��Ь(shoes)	һ����ʮ��
	ˮ��(bottle)	һ����

		���� Ƥ��(egg) ��ʮ�ģ���ˮ(not yet) xx�� \n"
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
