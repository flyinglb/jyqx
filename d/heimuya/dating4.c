//ROM dating
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ǡ�������̡��µ��Ĵ��ã������õĴ�����ԶԶ��ȥ��
�����죬���Ʋ�ʳ�˼��̻���������һ����(bian)��
LONG    );
        set("exits", ([
                "west" : __DIR__"road1",
                "southup" : __DIR__"tian1",
        ]));
        set("item_desc", ([
            "bian": "����д����������---�������ʥ��ס�ء�\n",
       	]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
