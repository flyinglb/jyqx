// Room: /d/mingjiao/mjdimen1.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

string look_pai();

void create()
{
    set("short", "�ſ�");
    set("long", @LONG
ǰ��������̵ġ������š��ˣ�������������Ů��������
�ĵط������ſڿ���ȥ������Ӱ�����˴´¡����ǽ�����Ů��
ȴҲ��������������롣�ſڻ�����һ��ľ��(mu pai)��
LONG );
    set("exits", ([
        "enter" : __DIR__"nushe",
        "southwest" : __DIR__"mjdimen",
    ]));
    set("item_desc",(["mu pai" : (: look_pai :),]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
//    replace_program(ROOM);
}

string look_pai()
{
	return
	"\n"
	"������������������������������������\n"
	"��                                ��\n"
	"��  �ô�Ů���ߣ�Ͷ���ˮ��̶�ܷ�����\n"
	"��                                ��\n"
        "��         ��������������ǫ ��    ��\n"
	"��                                ��\n"
	"������������������������������������\n";

}
