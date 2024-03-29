// waimaod.c 外貌

#include <ansi.h>

string query_waimao(string gender,int per)
{
	object obj=this_player();

	if ( gender == "男性"||gender == "无性" ) {
		switch(per)
		{
			case 39: return HIG"现在神清气爽，骨格清奇，宛若仙人。\n"NOR;
			case 38: return HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
			case 37: return HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
			case 36: return HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
			case 35: return HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
			case 34: return HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
			case 33: return HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
			case 32: return HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
			case 31: return HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
			case 30: return HIY"生得英俊潇洒，风流倜傥。\n"NOR;
			case 29: return MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
			case 28: return MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
			case 27: return MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
			case 26: return MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
			case 25: return MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
			case 24: return CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
			case 23: return CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
			case 22: return CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
			case 21: return CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
			case 20: return CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
			case 19: return YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
			case 18: return YEL"生得相貌平平，不会给人留下什么印相。\n"NOR;
			case 17: return YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
			case 16: return YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
			case 15: return YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
			case 14: return RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
			case 13: return RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
			case 12: return RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
			case 11: return RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
			default:
				if (per <= 10 ) return RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
				if (per >= 40 ) return HIW"现在一派神人气度，仙风道骨，举止出尘。\n"NOR;
		}
	}
	if ( gender == "女性"){
		switch(per)
		{
			case 39: return HIG"现在美若天仙，不沾一丝烟尘。\n"NOR;
			case 38: return HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
			case 37: return HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
			case 36: return HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
			case 35: return HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
			case 34: return HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
			case 33: return HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
			case 32: return HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
			case 31: return HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
			case 30: return HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
			case 29: return MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
			case 28: return MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
			case 27: return MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
			case 26: return MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
			case 25: return MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
			case 24: return CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
			case 23: return CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
			case 22: return CYN"生得巧笑嫣然，宛约可人。\n"NOR;
			case 21: return CYN"生得如梨花带露，清新秀丽。\n"NOR;
			case 20: return CYN"生得风姿楚楚，明丽动人。\n"NOR;
			case 19: return YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
			case 18: return YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
			case 17: return YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
			case 16: return YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
			case 15: return YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
			case 14: return RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
			case 13: return RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
			case 12: return RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
			case 11: return RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
			default:
				if (per >= 40) return HIW"现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物\n"NOR;
				if (per <= 10) return RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
		}
	}
}
