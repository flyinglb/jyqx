//modified by wind

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i,amount;
        object *inv;
        mapping exits,my;
        string str, *dirs;

        if( !env ) {
                if( !me->force_move_to_void() ) {
                        write("你的四周灰蒙蒙地一片，什么也没有。\n");
                        return 1;
                } else env = environment(me);
        }
//      str = sprintf( "%s - %s\n    %s%s",
        str = sprintf(HIG + "『 " + NOR  + HIR + "%s" + NOR + HIG + " 』" + NOR  +  " - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if(inv[i]->query("hide")) continue;

     if (inv[i]->query("money_id") || !inv[i]->query("unit")            || inv[i]->is_character()){  
     str+=sprintf("    %s\n",inv[i]->short()); 
           continue;        }
     if (!mapp(my))            my=([inv[i]->query("unit")+inv[i]->short():1]);        else{            amount=my[inv[i]->query("unit")+inv[i]->short()];            my[inv[i]->query("unit")+inv[i]->short()]=amount+1;        
         }    
     }     if(mapp(my)){     
     dirs=keys(my);   
     for(i=0;i<sizeof(my);i++)
     str+=sprintf("%s%s\n",my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),my[dirs[i]]==1?dirs[i][2..]:dirs[i]);    
     }  

     write(str);
     return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

    if (!me->visible(obj)) { write("你要看什么？\n"); return 1; }
      me->start_more(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("里面有：\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

int look_living(object me, object obj)
{
        string str, pro;
        mixed *inv;
        mapping my_fam, fam;
        int per,i;
        int me_shen, obj_shen;

        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

        str = obj->long();

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
                str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number((obj->query("age") - obj->query("lessage")) / 10 * 10));
        per = obj->query_per(); 
        if (per>9) {      
        if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
                if (per >= 30)
                  {     i=random(2);
                        if (i==0)
                        str += pro+"貌似潘安而略俊，神若游龙而约骄，态如玉树而更俏，\n"
                                   "当是须眉之中第一人。\n";
// look.c
                        if (i==1)
                        str += pro+"容颜俊俏，神采飞扬，气度万千，能引天女下凡尘。\n";
                  }
                if ((per >= 27) && (per < 30))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"玉树临风，风流倜傥，不知苦了多少女儿郎。\n";
                        if (i==1)
                        str += pro+"神采奕奕，顾盼生辉，光可照人，俊美非凡。\n";
                        if (i==2)
                        str += pro+"容光照人，秀美无比，引人疑为张仙转世。\n";
                  }
                if ((per >= 24) && (per < 27))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"神如秋水，态若春云，仪表堂堂。\n";
                        if (i==1)
                        str += pro+"书卷气浓而俗世之气少，遇之误为文曲星下凡。\n";
                  }
                if ((per >= 22) && (per < 24))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"身形高大，神气清俊，双眸有神，不怒自威。\n";
                        if (i==1)
                        str += pro+"眼神如同孤鹰，行动犹如疾风，威仪四方。\n";
                  }
                if ((per >= 20) && (per < 22))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"体形魁梧，肌肉虬结，精力充沛，容仪威猛。\n";
                        if (i==1)
                        str += pro+"傲气凛立，豪气干云，狂气冲天，一条好汉。\n";
                  }
                if ((per >= 18) && (per < 20))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"五短身材，相貌平平，毫无半点独特之处。\n";
                        if (i==1)
                        str += pro+"实在是个寻常之人，于人群中一站就再也无处找寻。\n";
                  }
                if ((per >= 15) && (per < 18))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"豹睛狼牙，狮鼻猩唇，满脸横肉，相貌凶顽。\n";
                        if (i==1)
                        str += pro+"生得獐头鼠目八字眉，罗圈腿儿佝偻背，\n"
                                   "不似常人，绝类波皮无赖。\n";
                  }
                if (per < 15)
                  {     i=random(2);
                        if (i==0)
                        str += pro+"容貌凶丑，日间见了疑非人类，晚间撞上惊为恶鬼！\n";
                        if (i==1)
                        str += pro+"长得不堪入目，实在是上对不起天，下对不起地，\n"
                                   "更对不起爹娘，注定今生打光棍。\n";
                  }
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >= 30)
                  {     i=random(3);
                        if (i==0)
                        str += pro+"，只见星眸朦胧而流光四溢，微启朱唇而鸟语四起，\n"
                                   "联袂轻移而花香弥漫，天上人间难觅之绝色！\n";
                        if (i==1)
                        str += pro+"天姿国色，秀绝人寰，红粉丛中第一人。有诗为证：\n"
                                   "“此姝原应天上有，不合生长在人间”。\n";
                        if (i==2)
                        str += pro+"国色天香，丽质天成，柔若无骨，美不胜收，\n"
                                   "惹多少儿郎暗生眷恋情……\n";
                  }
                if ((per >= 27) && (per < 30))
                  {     i=random(4);
                        if (i==0)
                        str += pro+"，只见朱唇绽处，娇同解语之花，眉无忧而长蹙，\n"
                                   "信乎西子而善颦，秋波转处，温云飘荡。\n";
                        if (i==1)
                        str += pro+"生得俏，粉颈玉琢引人凝望；生得巧，轻捷盈盈使人怜惜；\n"
                                   "生得妙，珠圆玉润哪堪增减；生得娇，娇颜欲滴惹人眷爱。\n";
                        if (i==2)
                        str += pro+"腮红酷似桃花，肌莹如同玉润，双星不动而眼波自流，\n"
                                   "寸步未移而身容忽转，真个销魂。\n";
                       if (i==3)
                        str += pro+"倩影涟涟，移步生香，殆色中之铮铮，闺中之矫矫者也。\n";
                  }
                if ((per >= 24) && (per < 27))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"姿同玉立，态如云行，风神绰卓，意志翩跹，妙在\n"
                                   "装束居浓淡之际，体态居肥瘦之间。\n";
                        if (i==1)
                        str += pro+"色多姝美，态有馀颜，轻不留痕，盈盈堪擎掌上，\n"
                                   "娇非作意，风神俨在画中。\n";
                        if (i==2)
                        str += pro+"风姿缥缈，幽情郁而未舒，秀外慧中，心事含而不吐，\n"
                                   "盖一妙然之丽人也。\n";
                  }
                if ((per >= 22) && (per < 24))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"容颜娇好，眉如黛，明眸善睐，唇如樱，香艳娇巧。\n";
                        if (i==1)
                        str += pro+"生得笑颜如花，玲珑小巧，甚是可人。\n";
                        if (i==2)
                        str += pro+"生得是“语焉悦耳，笑若花绽”，十分动人。\n";
                  }
                if ((per >= 20) && (per <22))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"“人窈窕，浑身满面都堆俏”，煞是可爱。\n";
                        if (i==1)
                        str += pro+"长得是“低眉顺眼颇少语，偶露笑颜甚乖巧”。\n";
                        if (i==2)
                        str += pro+"微笑露白齿，眼中透皎洁，顽皮可人。”。\n";
                  }
                if ((per >= 18) && (per <20))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"姿色寻常，倒也笑态可鞠，看得过去。\n";
                        if (i==1)
                        str += pro+"身形健硕，体态均匀，自有一番神采。\n";
                        if (i==2)
                        str += pro+"装束清淡，略施几分淡妆，倒也薄有两分姿色。”。\n";
                  }
                if ((per >= 16) && (per <18))
                  {     i=random(2);
                        if (i==0)
                        str += pro+"长得再一般不过，市井村巷平常见，见过不留半点痕。\n";
                        if (i==1)
                        str += pro+"相貌平平，世间如此女子何止千万，无需罔顾。\n";
                  }
                if ((per >= 14) && (per <16))
                  {     i=random(3);
                        if (i==0)
                        str += pro+"生得是“焦黄头发麻黑脸，只怕此生难出嫁”。\n";
                        if (i==1)
                        str += pro+"身材高大，臂上青筋暴起，倒象个男子。\n";
                        if (i==2)
                        str += pro+"生得腰如水桶，胸似鞠蹴，臂圆膀阔，好不难看。”。\n";
                  }
                if (per <14)
                  {     i=random(3);
                        if (i==0)
                        str += pro+"容貌生得甚恶，乍看类乎腌齄婆，细观近于罗刹鬼，\n"
                                   "怕是天上人间第一丑妇。\n";
                        if (i==1)
                        str += pro+"生得尴尬，见过恐要梦魇，不可再多看一眼！\n";
                        if (i==2)
                        str += pro+"长得好丑，痨弱病态哭丧脸，七分不大象人，\n"
                                   "倒有三分象鬼，怕会吓死他人。\n";
                  }
            }
            else  str += pro+"只是一只畜生而已，就是畜生的模样了。\n";
        }
        }
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }
        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  □" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
        return 1;
}


