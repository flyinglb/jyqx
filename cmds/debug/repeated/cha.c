// skills.c
// modified by wind

#include <ansi.h>

inherit F_CLEAN_UP;

/*
string *skill_level_desc = ({
	BLU "初学乍练" NOR,
	HIB "粗通皮毛" NOR,
	HIB "半生不熟" NOR,
	HIB "马马虎虎" NOR,
	HIB "驾轻就熟" NOR,
	CYN "出类拔萃" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,
	HIC "登峰造极" NOR,
	HIC "一代宗师" NOR,
	HIW "深不可测" NOR
});
*/

string *skill_level_desc = ({
	BLU "不堪一击" NOR,
	BLU "毫不足虑" NOR,
	BLU "不足挂齿" NOR,
	BLU "初学乍练" NOR,
	BLU "初窥门径" NOR,

	HIB "略知一二" NOR,
	HIB "普普通通" NOR,
	HIB "平平淡淡" NOR,
	HIB "平淡无奇" NOR,
	HIB "粗通皮毛" NOR,

	
        YEL "半生不熟" NOR,
	YEL "马马虎虎" NOR,
	YEL "略有小成" NOR,
	YEL "已有小成" NOR,
	YEL "驾轻就熟" NOR,

	HIY "心领神会" NOR,
	HIY "了然於胸" NOR,
	HIY "略有大成" NOR,
	HIY "已有大成" NOR,
	HIY "豁然贯通" NOR,

	CYN "出类拔萃" NOR,
	CYN "无可匹敌" NOR,
	CYN "技冠群雄" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,

	HIC "傲视群雄" NOR,
	HIC "登峰造极" NOR,
	HIC "所向披靡" NOR,
	HIC "一代宗师" NOR,
	HIC "神功盖世" NOR,

	MAG "举世无双" NOR,
	MAG "惊世骇俗" NOR,
	MAG "震古铄今" NOR,
	MAG "深藏不露" NOR,
	MAG "深不可测" NOR,

	HIM "皓月临空" NOR,
	HIM "月到天心" NOR,
 	HIM "风轻如水" NOR,
	HIM "水天一色" NOR,
	HIM "风月无边" NOR,

	HIW "返璞归真" NOR
});

string *knowledge_level_desc = ({
	BLU "不堪一击" NOR,
	BLU "毫不足虑" NOR,
	BLU "不足挂齿" NOR,
	BLU "初学乍练" NOR,
	BLU "初窥门径" NOR,

	HIB "略知一二" NOR,
	HIB "普普通通" NOR,
	HIB "平平淡淡" NOR,
	HIB "平淡无奇" NOR,
	HIB "粗通皮毛" NOR,

	
        YEL "半生不熟" NOR,
	YEL "马马虎虎" NOR,
	YEL "略有小成" NOR,
	YEL "已有小成" NOR,
	YEL "驾轻就熟" NOR,

	HIY "心领神会" NOR,
	HIY "了然於胸" NOR,
	HIY "略有大成" NOR,
	HIY "已有大成" NOR,
	HIY "豁然贯通" NOR,

	CYN "出类拔萃" NOR,
	CYN "无可匹敌" NOR,
	CYN "技冠群雄" NOR,
	CYN "神乎其技" NOR,
	CYN "出神入化" NOR,

	HIC "傲视群雄" NOR,
	HIC "登峰造极" NOR,
	HIC "所向披靡" NOR,
	HIC "一代宗师" NOR,
	HIC "神功盖世" NOR,

	MAG "举世无双" NOR,
	MAG "惊世骇俗" NOR,
	MAG "震古铄今" NOR,
	MAG "深藏不露" NOR,
	MAG "深不可测" NOR,

	HIM "皓月临空" NOR,
	HIM "月到天心" NOR,
 	HIM "风轻如水" NOR,
	HIM "水天一色" NOR,
	HIM "风月无边" NOR,

	HIW "返璞归真" NOR

});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped;
	int i;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else {
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的技能？\n");
	}

	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) )
		return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前所学过的技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "□"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象或你的配偶，用 skills 可以查知对方的
技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
