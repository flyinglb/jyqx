// skill.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping wprepare;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) ) skills = ([ skill: val ]);
        else skills[skill] = val;
}

int delete_skill(string skill)
{
        if( mapp(skills) ) {
                map_delete(skills, skill);
                if( mapp(learned) ) {
                        map_delete(learned, skill);
                        return undefinedp(learned[skill]);
                }
                return undefinedp(skills[skill]);
        }
        return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_map) ) {
                map_delete(skill_map, skill);
                return;
        }

        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;
                
        if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
        else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_prepare) ) {
                map_delete(skill_prepare, skill);
                return;
        }

        if( !find_object(SKILL_D(skill))
    &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;
                
        if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
        else skill_prepare[skill] = mapped_to;
}

// add for like prepare_skill
varargs void prepare_wskill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(wprepare) ) {
                map_delete(wprepare, skill);
                return;
        }

        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;
            if( !mapp(wprepare) ) wprepare = ([ skill: mapped_to ]);
        else wprepare[skill] = mapped_to;
}


string query_skill_mapped(string skill)
{
        if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
                return skill_map[skill];
        return 0;
}

string query_skill_prepared(string skill)
{
        if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
                return skill_prepare[skill];
        return 0;
}

string query_wprepared(string skill)
{
        if( mapp(wprepare) && !undefinedp(wprepare[skill]) )
       return wprepare[skill];
        return 0;
}

varargs int query_skill(string skill, int raw)
{
        if( !raw ) {
                int s;
                
                s = query_temp("apply/" + skill);
                if( mapp(skills) ) {
                        s += skills[skill] / 2;
                        if( mapp(skill_map) )
                                s += skills[skill_map[skill]];
                }
                return s;
        }
        if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
        return 0;
}

mapping query_skill_map()
{
       return skill_map;
}

mapping query_skill_prepare()
{
        return skill_prepare;
}

mapping query_wprepare()
{
       return wprepare;  
}

int skill_death_penalty()
{
        string *sk;
        int i,j;
        string force_skill;

        if( wizardp(this_object()) || !mapp(skills) ) return 0;
        j = 0;
        if( stringp(force_skill = this_object()->query_skill_mapped("force")) )
                j = 1;
        sk = keys(skills);
        if( !mapp(learned) )
                for(i = 0; i<sizeof(sk); i++) {
                        skills[sk[i]]--;
                        if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
                }
        else
                for(i = 0; i<sizeof(sk); i++) {
                        if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
                                map_delete(learned, sk[i]);
                        else {
                                skills[sk[i]]--;
                                if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
                        }
                }
        skill_map = 0;
        skill_prepare = 0;
        wprepare = 0;
        if (j = 1)
        {
                this_object()->map_skill("force", force_skill);
                this_object()->reset_action();
      }
        return 1;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
        int spi;

        if (!userp(this_object()))
                return;
        if (this_object()->is_ghost())
                return;
        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !weak_mode || !userp(this_object()) ) {
                if( !mapp(skills) ) skills = ([]);
                if( undefinedp(skills[skill]) ) skills[skill] = 0;
        }

        // Give learning penalty to those learning too much skills.
//      spi = query("spi");
        spi = 30; // set the default maximum to be 30 (CLEANSWORD CHANGED AT 5/27/96)
        if( sizeof(learned) > spi )
                amount /= sizeof(learned) - spi;
        if( !amount ) amount = 1;

        if( !mapp(learned) ) learned = ([ skill : amount ]);
        else (int)learned[skill] += amount;

        if( (!weak_mode || !userp(this_object()))
        &&      learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
                skills[skill]++;
                learned[skill] = 0;
                tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
                SKILL_D(skill)->skill_improved(this_object());
        }
}




