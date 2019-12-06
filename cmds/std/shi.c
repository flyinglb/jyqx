// poem.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
//	string arg;
 string *color = ({
RED,
HIR,
GRN,
HIG,
YEL,
HIY,
BLU,
HIB,
MAG,
HIM,
CYN,
HIC,
WHT,
HIW,
                });
	string *poem = ({
"花间一壶酒，独酌无相亲。"NOR,
"身无彩凤双飞翼，心有灵犀一点通。"NOR,
"停杯投箸不能食，拔剑四顾心茫然。"NOR,
"抽刀断水水更流，举杯销愁愁更愁。"NOR,
"十年磨一剑，霜寒未曾试。今日把问君，谁有不平事？"NOR,
"十四为君妇，羞颜未尝开。"NOR,
"春风不相识，何事入罗帏。"NOR,
"君不见，黄河之水天上来，奔流到海不复回。"NOR,
"云想衣裳花想容，春风拂槛露华浓。"NOR,
"名花倾国两相欢，常得君王带笑看。"NOR,
"噫吁戏，危乎高哉！蜀道之难，难于上青天。"NOR,
"明月出天山，苍茫云海间。"NOR,
"我醉欲眠卿且去，明朝有意抱琴来。"NOR,
"美人一笑褰珠箔，遥指红楼是妾家。"NOR,
"五岳寻仙不辞远，一生好入名山游。"NOR,
"安能摧眉折腰事权贵，使我不得开心颜。"NOR,
"一枝红艳露凝香，云雨巫山枉断肠。"NOR,
                });
	

//    	if( !this_object()->id(arg) ) return 0;
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致吟诗...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还吟诗...\n");
/*	
	if( (int)me->query_skill("literate",1)<100 )
		return notify_fail("你照着诗集摇头晃脑地哼了几句，不过没明白是啥意思。\n");
	if( (int)me->query_skill("literate",1)>140 )
		return notify_fail("你在文字方面已经很有造诣，这本书不会让你长进多少。\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")+1;
	me->improve_skill("literate", gain);
*/
        message_vision("$N高声吟道：" + color[random(sizeof(color))] + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

