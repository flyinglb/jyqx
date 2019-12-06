// Room: /d/npc/xianxianci.c

//inherit ROOM;
inherit CHATTING_ROOM;

void create()
{
	set("short", "先贤祠－巫师部");
	set("long",
"这里是纪念历代巫师的地方。每位在这里被供奉的巫师都为本MUD\n"
"做出过杰出的、不可磨灭的贡献。我们永远都会爱戴、怀念他们。抬头\n"
"一张横匾，上书七个闪闪发光的金字：\n"
"              "HBCYN"                              \n"NOR
"              "HBCYN"        "HIY"俯首甘为孺子牛        \n"NOR
"              "HBCYN"                              \n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"xxci1",
	]));
	set("no_fight",1);
        set("no_mask", 1);
	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/eatdami" : 1,
		"/d/npc/byp" : 1,
		"/d/npc/robin" : 1,
		"/d/npc/wind" : 1,
	]));

	setup();
//        replace_program(ROOM);
}
