//cave.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long",
	     "������̶�е�һ��С������������������м���ʯͷ��\n"
	);
	set("objects" , ([
             __DIR__"item/stone" : 1,
             ]) );
	setup();
	replace_program(ROOM);
}
