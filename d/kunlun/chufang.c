//Robin 2000.5.9

inherit ROOM;

void create()
{
	set("short","大厨房");
	set("long", @LONG
所谓大厨房并不是供给众多人吃饭的厨房，而是掌门人宅内的一个厨房，
仅供给掌门人及内眷的日常膳食，门下弟子是不能到这里吃饭的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chushi1" : 1,
	]));
	set("size",2);

	setup();
	replace_program(ROOM);
}
