// dating.c
inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���Ѿ�����÷ׯ�Ĵ����ſڣ����ڵ��Ҷ�(bian)���ɷ����д��
��������硱�ĸ����֣��ʷ�������͸��ͦ�Σ���ʧΪһ�ʺ��֡�͸
�����ţ��㿴������һ����Ⱦ��һ��ʯ���ͼ���ʯ�ʶ����ŵ�������
�롣
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
            "bian" : "������Ѿ��ܳ¾��ˣ�������ҡҡ�λεģ��ƺ������ʵ��\n",
        ]));
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"keting",
            "south" : __DIR__"tianjing",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

