#include <room.h>
//inherit ROOM;
inherit CHATTING_ROOM;

void create()
{
	set("short", "先贤祠－玩家部");
	set("long",
"这里是纪念杰出玩家的地方。供奉在这里的无论是侠客还是魔头，\n"
"都曾经叱诧一时。抬头一张横匾，上书七个闪闪发光的金字：\n"
"        "HBBLU"                                         \n"NOR
"        "HBBLU"              "HIY"天下谁人不识君             \n"NOR
"        "HBBLU"                                         \n"NOR
"··注：排名不分先后。按字母顺序。··\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"xxci2",
		"down" : __DIR__"shuyuan2",
//              "south" : __DIR__"xxci3",
	]));
	set("no_fight",1);
        set("no_mask", 1);

	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/lyz" : 1,
		"/d/npc/robin" : 1,
		"/d/npc/yeah" : 1,
		"/d/npc/xyz" : 1,
		"/d/npc/sybase" : 1,
                "/d/npc/winds" : 1,
                "/d/npc/yedou":1,
                "/d/npc/cbr":1,
                "/d/npc/yuan":1,
                "/d/npc/heihei":1,
                "/d/npc/yingxiong" : 1,
                "/d/npc/roujing":1,
                "/d/npc/qibao":1,
                "/d/npc/baoning":1,
                "/d/npc/andyzhu":1,
                "/d/npc/cqcq":1,
                "/d/npc/szb":1,
                "/d/npc/lovenow":1,
                "/d/npc/hpph":1,
                "/d/npc/again":1,
                "/d/npc/pipipipi":1,
                "/d/npc/xnet":1,
                "/d/npc/mok":1,
                "/d/npc/huanyun":1,
                "/d/npc/tiandao":1,
                "/d/npc/yueliang":1,
//              "/d/npc/xxxl":1,
                "/d/npc/anf":1,
                "/d/npc/fangz":1,
                "/d/npc/shoe":1,
                "/d/npc/chz":1,
                "/d/npc/never":1,
                "/d/npc/songxin":1,
                "/d/npc/frost":1,
                "/d/npc/fengfeng":1,
                "/d/npc/qqqqq":1,
                "/d/npc/pos":1,
                "/d/npc/yubing":1,
                "/d/npc/netbai":1,
                "/d/npc/gms":1,
                "/d/npc/ace":1,
                "/d/npc/boboy":1,
                "/d/npc/sno":1,
                "/d/npc/sdlkx":1,
	]));

//        create_door("south","木门","north",DOOR_CLOSED)
	setup();
}
