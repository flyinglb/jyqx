// neiyuan.c
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
������÷ׯ����Ժ���������߹�ȥ�Ϳ����ҵ���λׯ����������
���ǳ�����������������Ҷ���ص������������ƺ��ǳ����֣�������
���������ӵ����������������ֿ��Խ�������Ҵ��ң����治֪����
��ô��������ط�����һλ׳��ĺ��ӣ�������������Ժ�ſڡ�
LONG
        );
        set("outdoors", "meizhuang");
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"senlin1",
            "north" : __DIR__"zoulang1",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/huyuan.c" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

