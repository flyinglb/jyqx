// zoulang2.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����������ȣ�������������λׯ���е�������λƽʱ��
Ϣ�������ĵط����������������ң��ұ�����÷ׯ���Ӹо��Ͷٵ�
ʱ����Ϣ�ĵط�����ׯ���ڰ��Ӳ�����ҹ�����������о�����Щ��֪
���Ķ������Ĺ����ס� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"qishi",
            "east" : __DIR__"xiuxishi",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

