// Room: /d/mr/hubian.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�׻�˵ : ��������, �����պ����������Ǵ��������̫���� �����̲�
��Ư��һҶҶ��С��, һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ�
�С�
LONG
        );
        set("outdoors", "mr");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"hubian1",
//  "west" : "/d/mr/syj",
  "northeast" : "/d/suzhou/road5",
]));

        setup();
        replace_program(ROOM);
}


