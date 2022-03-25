c V2toV4.cc Use this table to upgrade a dictionary
c from DDP version 2 to version 4.

group(1)
'\is ' > dup back(1) use(2)
group(2)
'\' > dup back(1) use(1)
' 1.1.1' nl > ' 1.1' nl c Objects in the sky
' 1.1.1.1' nl > ' 1.1.1' nl c Sun
' 1.1.1.2' nl > ' 1.1.1.1' nl c Moon
' 1.1.1.3' nl > ' 1.1.1.2' nl c Star
' 1.1.1.4' nl > ' 1.1.1.3' nl c Planet
' 1.1.3.1.1' nl > ' 1.1.2.1' nl c Blow air
' 1.2.2.6' nl > ' 1.2.3' nl c Solid, liquid, gas
' 1.2.2.7' nl > ' 1.2.3.1' nl c Liquid
' 1.2.2.8' nl > ' 1.2.3.2' nl c Oil
' 1.2.2.9' nl > ' 1.2.3.3' nl c Gas
' 2.1' nl > ' 4.1.2' nl c Types of people
' 2.2' nl > ' 2.1' nl c Body
' 2.2.1' nl > ' 2.1.1' nl c Head
' 2.2.2' nl > ' 2.1.2' nl c Torso
' 2.2.3' nl > ' 2.1.3' nl c Arm, leg
' 2.2.3.1' nl > ' 2.1.3.1' nl c Arm
' 2.2.3.2' nl > ' 2.1.3.2' nl c Leg
' 2.2.3.3' nl > ' 2.1.3.3' nl c Finger, toe
' 2.2.4' nl > ' 2.1.4' nl c Skin
' 2.2.5' nl > ' 2.1.5' nl c Hair
' 2.2.6' nl > ' 2.1.6' nl c Bone, joint
' 2.2.7' nl > ' 2.1.7' nl c Flesh
' 2.2.8' nl > ' 2.1.8' nl c Internal organs
' 2.2.8.1' nl > ' 2.1.8.3' nl c Male organs
' 2.2.8.2' nl > ' 2.1.8.4' nl c Female organs
' 2.3' nl > ' 2.2' nl c Body functions
' 2.3.1' nl > ' 2.1.1.1' nl c Functions of the eye
' 2.3.1.1' nl > ' 3.5.6.5' nl c Weep
' 2.3.2' nl > ' 2.1.1.2' nl c Functions of the ear
' 2.3.3' nl > ' 2.1.1.3' nl c Functions of the nose
' 2.3.4' nl > ' 2.1.1.4' nl c Functions of the mouth
' 2.3.4.1' nl > ' 2.2.3' nl c Spit, saliva
' 2.3.4.2' nl > ' 3.5.6.3' nl c Facial expressions
' 2.3.5' nl > ' 2.1.8.1' nl c Functions of the heart
' 2.3.5.1' nl > ' 2.2.5' nl c Bleed, blood
' 2.3.6' nl > ' 2.2.1' nl c Breathe, breath
' 2.3.7' nl > ' 2.1.8.2' nl c Functions of the stomach
' 2.3.7.1' nl > ' 2.2.8' nl c Defecate, feces
' 2.3.8' nl > ' 2.2.7' nl c Urinate, urine
' 2.3.9' nl > ' 2.2.6' nl c Sweat
' 2.4' nl > ' 2.3' nl c The senses
' 2.4.1' nl > ' 2.3.1' nl c See
' 2.4.1.1' nl > ' 2.3.1.1' nl c Look
' 2.4.1.2' nl > ' 2.3.1.9' nl c Something used to see
' 2.4.2' nl > ' 2.3.2' nl c Hear
' 2.4.2.1' nl > ' 2.3.2.2' nl c Sound
' 2.4.2.2' nl > ' 2.3.2.3' nl c Types of sounds
' 2.4.3' nl > ' 2.3.3' nl c Taste
' 2.4.4' nl > ' 2.3.4' nl c Smell
' 2.4.5' nl > ' 2.3.5' nl c Sense of touch
' 2.4.5.1' nl > ' 2.3.5.1' nl c Comfortable
' 2.5' nl > ' 2.4' nl c Body condition
' 2.5.1' nl > ' 2.4.4' nl c Tired
' 2.5.2' nl > ' 2.4.5' nl c Rest
' 2.5.3' nl > ' 2.4.1' nl c Strong
' 2.5.4' nl > ' 2.4.2' nl c Weak
' 2.6' nl > ' 2.5' nl c Healthy
' 2.6.1' nl > ' 2.5.1' nl c Sick
' 2.6.1.1' nl > ' 2.5.1.1' nl c Recover from sickness
' 2.6.2' nl > ' 2.5.2' nl c Disease
' 2.6.2.1' nl > ' 2.5.2.1' nl c Malnutrition, starvation
' 2.6.2.2' nl > ' 2.5.2.2' nl c Skin disease
' 2.6.2.3' nl > ' 2.5.2.2' nl c Leprosy
' 2.6.2.4' nl > ' 2.5.2.3' nl c Stomach illness
' 2.6.2.5' nl > ' 2.5.2.4' nl c Tooth decay
' 2.6.3' nl > ' 2.5.3' nl c Injured
' 2.6.3.1' nl > ' 2.5.3.1' nl c Amputation
' 2.6.3.2' nl > ' 2.5.3.2' nl c Poison
' 2.6.4' nl > ' 2.5.4' nl c Disabled
' 2.6.4.1' nl > ' 2.5.4' nl c Crippled
' 2.6.4.2' nl > ' 2.5.4' nl c Paralyzed
' 2.6.4.3' nl > ' 2.5.4.1' nl c Blind
' 2.6.4.4' nl > ' 2.5.4.2' nl c Poor eyesight
' 2.6.4.5' nl > ' 2.5.4.3' nl c Deaf
' 2.6.4.6' nl > ' 2.5.4.4' nl c Mute
' 2.6.4.7' nl > ' 2.5.8' nl c Mentally disabled
' 2.6.5' nl > ' 2.5.6' nl c Symptoms of disease
' 2.6.5.1' nl > ' 2.5.6.1' nl c Pain
' 2.6.5.2' nl > ' 2.5.6.2' nl c Fever
' 2.6.5.3' nl > ' 2.5.6.3' nl c Swell
' 2.6.6' nl > ' 2.5.7' nl c Treat disease
' 2.6.6.1' nl > ' 2.5.7' nl c Care for a sick person
' 2.6.6.2' nl > ' 2.5.3.2' nl c Treat for poisoning
' 2.6.6.3' nl > ' 2.5.7.1' nl c Doctor, nurse
' 2.6.6.4' nl > ' 2.5.7.2' nl c Medicine
' 2.6.6.5' nl > ' 2.5.7.3' nl c Medicinal plants
' 2.6.6.6' nl > ' 2.5.7.4' nl c Hospital
' 2.6.6.7' nl > ' 2.5.7.5' nl c Traditional medicine
' 2.7' nl > ' 2.6' nl c Life
' 2.7.1' nl > ' 2.6.1' nl c Marriage
' 2.7.1.1' nl > ' 2.6.1.1' nl c Arranging a marriage
' 2.7.1.2' nl > ' 2.6.1.2' nl c Wedding
' 2.7.1.3' nl > ' 2.6.1.3' nl c Unmarried
' 2.7.1.4' nl > ' 2.6.1.4' nl c Divorce
' 2.7.2' nl > ' 2.6.2' nl c Sexual relations
' 2.7.2.1' nl > ' 2.6.2.1' nl c Virginity
' 2.7.2.2' nl > ' 2.6.2.2' nl c Sexually attracted
' 2.7.2.3' nl > ' 2.6.2.3' nl c Sexual misbehavior
' 2.7.3' nl > ' 2.6.3' nl c Birth
' 2.7.3.1' nl > ' 2.6.3.1' nl c Pregnancy
' 2.7.3.1.1' nl > ' 2.6.3.2' nl c Fetus
' 2.7.3.1.2' nl > ' 2.6.3.3' nl c Miscarriage
' 2.7.3.2' nl > ' 2.6.3' nl c Give birth
' 2.7.3.2.1' nl > ' 2.6.3.4' nl c Labor and birth pains
' 2.7.3.2.2' nl > ' 2.6.3.5' nl c Help to give birth
' 2.7.3.3' nl > ' 2.6.3.6' nl c Unusual birth
' 2.7.3.4' nl > ' 2.6.3.7' nl c Multiple births
' 2.7.3.5' nl > ' 2.6.3.9' nl c Birth ceremony
' 2.7.3.6' nl > ' 2.6.3.8' nl c Barren, childless
' 2.7.4' nl > ' 2.6.4' nl c Stage of life
' 2.7.4.1' nl > ' 2.6.4.1' nl c Baby
' 2.7.4.1.1' nl > ' 2.6.4.1.1' nl c Care for a baby
' 2.7.4.2' nl > ' 2.6.4.2' nl c Child
' 2.7.4.2.1' nl > ' 2.6.4.2.1' nl c Rear a child
' 2.7.4.3' nl > ' 2.6.4.3' nl c Youth
' 2.7.4.4' nl > ' 2.6.4.4' nl c Adult
' 2.7.4.5' nl > ' 2.6.4.5' nl c Older person
' 2.7.4.6' nl > ' 2.6.4.6' nl c Grow, mature
' 2.7.4.7' nl > ' 2.6.4.7' nl c Initiation
' 2.7.4.8' nl > ' 2.6.4.8' nl c Peer group
' 2.7.5' nl > ' 2.6.5' nl c Male, female
' 2.7.5.1' nl > ' 2.6.5.1' nl c Man
' 2.7.5.2' nl > ' 2.6.5.2' nl c Woman
' 2.7.6' nl > ' 2.6.6' nl c Die
' 2.7.6.1' nl > ' 2.6.6.1' nl c Kill
' 2.7.6.2' nl > ' 2.6.6.2' nl c Corpse
' 2.7.6.3' nl > ' 2.6.6.5' nl c Bury
' 2.7.6.4' nl > ' 2.6.6.6' nl c Grave
' 2.7.6.5' nl > ' 2.6.6.3' nl c Funeral
' 2.7.6.6' nl > ' 2.6.6.4' nl c Mourn
' 3.1.2.2' nl > ' 2.5.6.5' nl c Dazed, confused
' 3.1.2.3' nl > ' 2.5.6.4' nl c Lose consciousness
' 3.1.2.4' nl > ' 2.5.6.6' nl c Vision, hallucination
' 3.2' nl > ' 3.2.1' nl c Mind
' 3.2.1' nl > ' 3.2' nl c Think
' 3.2.1.1' nl > ' 3.2.2.1' nl c Investigate
' 3.2.1.1.1' nl > ' 3.2.2.2' nl c Check
' 3.2.1.2' nl > ' 3.2.2.4' nl c Guess
' 3.2.1.3' nl > ' 3.2.2.3' nl c Evaluate, test
' 3.2.1.3.1' nl > ' 3.2.5.9' nl c Approve
' 3.2.1.4' nl > ' 3.2.1.2' nl c Imagine
' 3.2.1.5' nl > ' 3.2.1.3' nl c Intelligent
' 3.2.1.6' nl > ' 3.2.1.4' nl c Stupid
' 3.2.1.7' nl > ' 3.2.1.5' nl c Logical
' 3.2.1.8' nl > ' 3.2.2.5' nl c Solve
' 3.2.1.9' nl > ' 3.2.1.6' nl c Instinct
' 3.2.2.1' nl > ' 3.2.2.7' nl c Willing to learn
' 3.2.2.2' nl > ' 3.1.2.2' nl c Notice
' 3.2.4.3' nl > ' 3.5.8.1' nl c Meaning
' 3.2.5.3' nl > ' 3.2.5.4' nl c Agree
' 3.2.5.4' nl > ' 3.2.5.5' nl c Philosophy
' 3.2.5.5' nl > ' 3.2.5.6' nl c Attitude
' 3.2.5.6' nl > ' 3.2.5.7' nl c Extreme belief
' 3.2.5.7' nl > ' 3.2.5.8' nl c Change your mind
' 3.2.7.2' nl > ' 3.4.2.1.4' nl c Disappointed
' 3.2.7.3' nl > ' 3.2.7.2' nl c Hopeless
' 3.2.8' nl > ' 3.5.1.3' nl c True
' 3.2.8.1' nl > ' 3.2.5.3' nl c Doubt
' 3.2.8.2' nl > ' 3.2.8' nl c Tendency
' 3.3.1' nl > ' 3.3' nl c Want
' 3.3.1.1' nl > ' 3.3.1.8' nl c Lust
' 3.3.2.1' nl > ' 6.8.3.4' nl c Beg
' 3.3.2.2' nl > ' 3.3.2' nl c Plead
' 3.3.2.3' nl > ' 3.3.4.1' nl c Give consent
' 3.3.2.4' nl > ' 3.3.5' nl c Offer
' 3.3.2.5' nl > ' 3.3.5.2' nl c Reject
' 3.3.2.6' nl > ' 3.3.4.2' nl c Refuse
' 3.3.3.2' nl > ' 3.3.3.3' nl c Persuade
' 3.3.3.3' nl > ' 3.3.3.2' nl c Advise
' 3.3.3.9' nl > ' 3.3.2.3' nl c Intercede
' 3.3.4' nl > ' 3.3.1' nl c Decide, plan
' 3.3.4.1' nl > ' 3.3.1.4' nl c Intend
' 3.3.4.2' nl > ' 3.3.1.1' nl c Goal
' 3.3.4.3' nl > ' 3.3.1.1' nl c Purposeless
' 3.3.4.4' nl > ' 3.3.1.3' nl c Casting lots
' 3.3.4.5' nl > ' 3.3.1.2' nl c Choose
' 3.3.4.6' nl > ' 8.3.7.7.2' nl c Convenient
' 3.3.5' nl > ' 3.3.2.4' nl c Willing
' 3.3.5.1' nl > ' 3.3.1.6' nl c Determined
' 3.3.5.2' nl > ' 3.3.1.7' nl c Stubborn
' 3.3.5.3' nl > ' 3.3.1.5' nl c Deliberately
' 3.3.6' nl > ' 3.3.4.5' nl c Freedom
' 3.4.1.1.1' nl > ' 3.4.1.1.2' nl c Self-esteem
' 3.4.1.2.1' nl > ' 3.5.6.4' nl c Laugh
' 3.4.1.2.2' nl > ' 3.4.1.2.1' nl c Relaxed
' 3.4.1.2.3' nl > ' 3.4.1.2.2' nl c Calm
' 3.4.1.4.3' nl > ' 3.4.1.4.4' nl c Attract
' 3.4.1.4.4' nl > ' 3.4.1.4.5' nl c Indifferent
' 3.4.1.4.5' nl > ' 3.4.1.4.6' nl c Boring
' 3.4.2.2' nl > ' 3.4.2.1.5' nl c Lonely
' 3.4.2.3' nl > ' 3.4.2.1.1' nl c Dislike, abhor
' 3.4.2.4' nl > ' 3.4.2.4.3' nl c Shy, timid
' 3.4.2.5' nl > ' 3.4.2.3' nl c Angry
' 3.4.2.6' nl > ' 3.4.2.1.6' nl c Upset, discontent
' 3.4.2.7' nl > ' 3.4.2.4' nl c Fear
' 3.4.2.7.1' nl > ' 3.4.2.4.1' nl c Worry
' 3.4.2.7.2' nl > ' 3.4.2.4.2' nl c Nervous
' 3.4.2.8' nl > ' 3.4.2.1.7' nl c Shock
' 3.4.2.9' nl > ' 3.4.2.1.8' nl c Jealous
' 3.5.1.2' nl > ' 3.5.2' nl c Make speech
' 3.5.1.2.2' nl > ' 3.5.1.2.8' nl c Emphasize
' 3.5.1.3' nl > ' 3.5.1.2.6' nl c Repeat
' 3.5.1.3.1' nl > ' 3.5.1.2.7' nl c Summarize
' 3.5.1.4.2' nl > ' 3.5.1.4.3' nl c Greet
' 3.5.1.4.3' nl > ' 3.5.1.4.4' nl c Say farewell
' 3.5.1.4.4' nl > ' 3.5.1.4.5' nl c Speak in unison
' 3.5.1.7' nl > ' 3.5.1.7.3' nl c Boast
' 3.5.1.8' nl > ' 3.5.1.2.5' nl c Introduce
' 3.5.2' nl > ' 3.5.2.1' nl c Report
' 3.5.2.1' nl > ' 3.5.2.2' nl c News, message
' 3.5.2.2' nl > ' 3.5.1.2.2' nl c Describe
' 3.5.2.3' nl > ' 3.5.1.3.6' nl c Exaggerate
' 3.5.2.4' nl > ' 3.5.2.3' nl c Figurative
' 3.5.2.5' nl > ' 3.5.3.2' nl c Information
' 3.5.2.6' nl > ' 3.5.2.4' nl c Admit
' 3.5.2.7' nl > ' 3.5.5' nl c Foolish talk
' 3.5.2.8' nl > ' 3.5.5.1' nl c Obscenity
' 3.5.3.2' nl > ' 9.7.1' nl c Name of a person
' 3.5.3.3' nl > ' 9.7.3' nl c Name of a thing
' 3.5.4' nl > ' 3.5.4.6' nl c Verbal tradition
' 3.5.5' nl > ' 3.5.7' nl c Reading and writing
' 3.5.5.1' nl > ' 3.5.7.1' nl c Write
' 3.5.5.2' nl > ' 3.5.7.2' nl c Written material
' 3.5.5.3' nl > ' 3.5.7.3' nl c Read
' 3.5.5.4' nl > ' 3.5.7.4' nl c Publish
' 3.5.5.5' nl > ' 3.5.7.5' nl c Record
' 3.5.5.6' nl > ' 3.5.7.6' nl c List
' 3.5.7' nl > ' 3.5.8' nl c Interpreting messages
' 3.5.7.1' nl > ' 3.5.8.1' nl c Meaning
' 3.5.7.2' nl > ' 3.5.8.2' nl c Meaningless
' 3.5.7.3' nl > ' 3.5.8.3' nl c Unintelligible
' 3.5.7.4' nl > ' 3.5.8.4' nl c Show, indicate
' 3.5.8' nl > ' 3.5.9' nl c Mass communication
' 3.5.8.1' nl > ' 3.5.9.1' nl c Radio, television
' 3.5.8.2' nl > ' 3.5.9.2' nl c Telephone
' 3.5.8.3' nl > ' 3.5.9.3' nl c Newspaper
' 3.5.8.4' nl > ' 3.5.9.4' nl c Movie
' 3.5.8.5' nl > ' 3.5.9.5' nl c Recorded music
' 3.5.9' nl > ' 3.5.9.6' nl c Communication devices
' 3.6.4' nl > ' 3.2.2' nl c Learn, study
' 4.1.2' nl > ' 4.1.2.1' nl c Working relationship
' 4.2.1.4' nl > ' 4.2.1.7' nl c Crowd, group
' 4.2.1.4.1' nl > ' 4.2.1.8.1' nl c Join a group
' 4.2.1.4.2' nl > ' 4.2.1.8.2' nl c Leave a group
' 4.2.1.4.3' nl > ' 4.2.1.8.3' nl c Belong to a group
' 4.2.1.7' nl > ' 4.2.1.6' nl c Bystander
' 4.2.1.8' nl > ' 4.2.1.4' nl c Visit
' 4.2.1.8.1' nl > ' 4.2.1.4.1' nl c Welcome, receive
' 4.2.1.8.2' nl > ' 4.2.1.4.2' nl c Show hospitality
' 4.2.2.2' nl > ' 4.2.2.3' nl c Celebrate
' 4.2.6.1.1' nl > ' 4.2.6.4' nl c Gambling
' 4.2.6.2.1' nl > ' 4.2.6.2.2' nl c Sport#1
' 4.3' nl > ' 4.3.9' nl c Culture
' 4.3.1' nl > ' 4.3.9.1' nl c Custom
' 4.3.2' nl > ' 4.3.9.2' nl c Habit
' 4.4' nl > ' 4.3' nl c Behavior
' 4.4.1' nl > ' 4.3.4' nl c Do something good
' 4.4.1.1' nl > ' 4.3.1' nl c Morally good
' 4.4.1.1.1' nl > ' 4.3.1.2' nl c Meet a standard
' 4.4.1.1.2' nl > ' 4.3.1.3' nl c Act maturely
' 4.4.1.1.3' nl > ' 4.3.2.2' nl c Humble
' 4.4.1.1.4' nl > ' 4.3.1.5' nl c Patient
' 4.4.1.1.5' nl > ' 4.3.1.4' nl c Have a good reputation
' 4.4.1.2' nl > ' 4.3.3' nl c Love
' 4.4.1.2.1' nl > ' 4.3.2' nl c Think well of
' 4.4.1.2.2' nl > ' 4.3.3' nl c Wish well
' 4.4.1.2.3' nl > ' 3.4.1.1.8' nl c Pleased with
' 4.4.1.2.4' nl > ' 3.5.1.7.1' nl c Thank
' 4.4.1.2.5' nl > ' 3.4.1.1.7' nl c Happy for
' 4.4.1.2.6' nl > ' 3.4.1.1.6' nl c Contentment
' 4.4.1.3' nl > ' 4.3.4' nl c Do good to
' 4.4.1.3.1' nl > ' 4.3.4.2' nl c Help
' 4.4.1.3.2' nl > ' 4.3.4.3' nl c Cooperate with
' 4.4.1.3.3' nl > ' 4.3.4.4' nl c Altruistic, selfless
' 4.4.1.3.4' nl > ' 4.3.4.5' nl c Share with
' 4.4.1.3.5' nl > ' 4.3.4.5.2' nl c Care for
' 4.4.1.3.6' nl > ' 4.3.4.5.1' nl c Provide for, support
' 4.4.1.3.7' nl > ' 4.3.4.5.3' nl c Entrust to the care of
' 4.4.1.3.8' nl > ' 4.3.5.2' nl c Faithful
' 4.4.1.4' nl > ' 3.5.1.7' nl c Speak well of
' 4.4.1.5' nl > ' 3.5.1.3.1' nl c Speak truth
' 4.4.1.5.1' nl > ' 3.5.1.3.4' nl c Expose falsehood
' 4.4.1.6' nl > ' 4.3.6' nl c Self-controlled
' 4.4.1.6.1' nl > ' 4.3.6.2' nl c Orderly
' 4.4.1.6.2' nl > ' 4.3.7' nl c Social refinement
' 4.4.1.7' nl > ' 4.3.5.3' nl c Reliable
' 4.4.1.8' nl > ' 4.3.1.3.2' nl c Thoughtful, sensible
' 4.4.1.9' nl > ' 4.3.8' nl c Change behavior
' 4.4.2' nl > ' 4.3.4.1' nl c Do something bad
' 4.4.2.1' nl > ' 4.3.1.1' nl c Bad person
' 4.4.2.1.1' nl > ' 4.3.1.1' nl c Morally evil
' 4.4.2.1.2' nl > ' 4.3.1.2.1' nl c Below standard
' 4.4.2.1.3' nl > ' 4.3.1.3.1' nl c Immature
' 4.4.2.1.4' nl > ' 4.3.2.3' nl c Proud
' 4.4.2.1.5' nl > ' 4.3.1.5.1' nl c Impatient
' 4.4.2.1.6' nl > ' 4.3.1.4' nl c Have a bad reputation
' 4.4.2.1.7' nl > ' 3.3.1.7' nl c Obstinate
' 4.4.2.1.8' nl > ' 4.3.1.5.2' nl c Bad-tempered
' 4.4.2.1.9' nl > ' 4.3.8.1' nl c Unconformity
' 4.4.2.2' nl > ' 4.3.3.1' nl c Feel evil toward
' 4.4.2.2.1' nl > ' 4.3.2.1' nl c Think poorly of
' 4.4.2.2.2' nl > ' 4.3.3.1' nl c Wish evil on
' 4.4.2.2.3' nl > ' 3.4.2.1.1' nl c Displeased with
' 4.4.2.2.4' nl > ' 3.5.1.7.1' nl c Ungrateful
' 4.4.2.2.5' nl > ' 3.4.2.1.9' nl c Discontent
' 4.4.2.2.6' nl > ' 4.3.3.2' nl c Not care
' 4.4.2.2.7' nl > ' 3.4.2.3' nl c Resent, bear a grudge
' 4.4.2.3' nl > ' 4.3.4.1' nl c Do evil to
' 4.4.2.3.1' nl > ' 4.3.4.2.1' nl c Hinder
' 4.4.2.3.2' nl > ' 4.3.4.3.1' nl c Compete with
' 4.4.2.3.3' nl > ' 4.3.4.4.1' nl c Selfish
' 4.4.2.3.4' nl > ' 4.3.4.4.2' nl c Exploit
' 4.4.2.3.5' nl > ' 3.1.2.4' nl c Ignore
' 4.4.2.3.6' nl > ' 4.8.2.5' nl c Revenge
' 4.4.2.3.7' nl > ' 4.3.4.6' nl c Meddle
' 4.4.2.3.8' nl > ' 4.3.4.7' nl c Enter by force
' 4.4.2.3.9' nl > ' 3.4.2.3.1' nl c Annoy
' 4.4.2.4' nl > ' 3.5.1.8' nl c Speak evil of
' 4.4.2.4.1' nl > ' 3.5.1.8' nl c Criticize
' 4.4.2.4.2' nl > ' 3.5.1.8.2' nl c Insult
' 4.4.2.4.3' nl > ' 3.5.1.8.4' nl c Gossip
' 4.4.2.4.4' nl > ' 3.5.1.6.2' nl c Quarrel
' 4.4.2.4.5' nl > ' 3.4.2.3' nl c Provoke
' 4.4.2.4.6' nl > ' 3.5.1.3.3' nl c Contradict
' 4.4.2.4.8' nl > ' 3.5.1.7.2' nl c Flatter
' 4.4.2.4.9' nl > ' 3.5.1.8.3' nl c Mock
' 4.4.2.5' nl > ' 4.3.5.1' nl c Dishonest
' 4.4.2.5.1' nl > ' 3.5.1.3.2' nl c Lie, speak untruth
' 4.4.2.5.2' nl > ' 4.3.5.5' nl c Deceive
' 4.4.2.5.3' nl > ' 4.3.5.6' nl c Hypocrite
' 4.4.2.6' nl > ' 4.3.6.1' nl c Lack self-control
' 4.4.2.6.1' nl > ' 4.3.6.3' nl c Messy
' 4.4.2.6.2' nl > ' 4.3.6.4' nl c Make a mistake
' 4.4.2.6.3' nl > ' 4.3.7.1' nl c Impolite
' 4.4.2.7' nl > ' 4.3.5.4' nl c Unreliable
' 4.4.2.7.1' nl > ' 3.5.1.9' nl c Go back on promise
' 4.4.2.7.2' nl > ' 4.8.2.7' nl c Betray
' 4.4.2.8' nl > ' 4.3.4.9' nl c Cruel
' 4.4.2.9' nl > ' 4.3.7.2' nl c Crazy
' 4.4.3' nl > ' 4.3.8.1' nl c Conform
' 4.5' nl > ' 4.4' nl c Prosperity, trouble
' 4.5.1' nl > ' 4.4.1' nl c Prosperity
' 4.5.2' nl > ' 4.4.2' nl c Trouble
' 4.5.2.1' nl > ' 4.4.2.1' nl c Problem
' 4.5.2.2' nl > ' 4.4.2.2' nl c Danger
' 4.5.2.3' nl > ' 4.8.2.6' nl c Disorder, commotion
' 4.5.2.4' nl > ' 4.4.2.5' nl c Separate, alone
' 4.5.2.4.1' nl > ' 4.3.3.3' nl c Abandon
' 4.5.2.5' nl > ' 4.4.5.2' nl c Unfortunate
' 4.5.2.6' nl > ' 4.8.3.5' nl c Captivity
' 4.5.2.7' nl > ' 4.4.2.3' nl c Accident
' 4.5.2.8' nl > ' 4.4.2.6' nl c Suffer
' 4.5.2.9' nl > ' 4.4.2.4' nl c Disaster
' 4.5.3' nl > ' 4.4.3' nl c Respond to trouble
' 4.5.3.1' nl > ' 4.4.3.1' nl c Courage
' 4.5.3.2' nl > ' 4.4.3.2' nl c Cowardice
' 4.5.3.3' nl > ' 4.4.3.3' nl c Avoid trouble
' 4.5.3.4' nl > ' 4.4.4.5' nl c Guard something dangerous
' 4.5.3.5' nl > ' 4.4.3.4' nl c Caution
' 4.5.3.6' nl > ' 4.8.1.1' nl c Resist
' 4.5.3.7' nl > ' 4.4.3.5' nl c Solve a problem
' 4.5.3.8' nl > ' 4.4.3.6' nl c Endure
' 4.5.4' nl > ' 4.4.4' nl c Respond to someone in trouble
' 4.5.4.1' nl > ' 4.4.4.1' nl c Have mercy
' 4.5.4.2' nl > ' 4.4.4.2' nl c Show sympathy, support
' 4.5.4.3' nl > ' 4.4.4.3' nl c Gentle
' 4.5.4.4' nl > ' 4.4.4.4' nl c Save from trouble
' 4.5.4.5' nl > ' 4.4.4.5' nl c Defend from danger
' 4.5.4.6' nl > ' 4.4.4.6' nl c Free from bondage
' 4.5.4.7' nl > ' 4.4.4.7' nl c Relief
' 4.5.4.8' nl > ' 4.4.4.8' nl c Risk
' 4.5.5' nl > ' 4.4.5' nl c Chance
' 4.6.1' nl > ' 4.5.1' nl c Person in authority
' 4.6.1.1' nl > ' 4.6.1' nl c Supreme authority
' 4.6.1.2' nl > ' 4.6.1.1' nl c King's family
' 4.6.1.3' nl > ' 4.6.1.2' nl c King's subordinate
' 4.6.3.1' nl > ' 4.6.3.1' nl c Governing bodies
' 4.6.4' nl > ' 4.5' nl c Authority
' 4.6.4.1' nl > ' 4.5.2' nl c Have authority
' 4.6.4.2' nl > ' 4.5.3' nl c Exercise authority
' 4.6.4.3' nl > ' 4.5.3.4' nl c Appoint, delegate
' 4.6.4.4' nl > ' 4.6.4' nl c Rule
' 4.6.4.5' nl > ' 4.5.3.1' nl c Lead
' 4.6.4.5.1' nl > ' 4.5.3.3' nl c Discipline, train
' 4.6.4.5.2' nl > ' 4.5.4.1' nl c Obey
' 4.6.4.5.3' nl > ' 4.5.4.2' nl c Disobey
' 4.6.4.5.4' nl > ' 4.5.4.5' nl c Follow, be a disciple
' 4.6.4.6' nl > ' 4.5.3.1' nl c Leadership
' 4.6.4.7' nl > ' 4.6.5' nl c Subjugate
' 4.6.4.8' nl > ' 4.8.2.7' nl c Hand over, betray
' 4.6.5' nl > ' 4.5.3.2' nl c Command
' 4.6.5.1' nl > ' 3.3.4.1' nl c Permit
' 4.6.5.2' nl > ' 3.3.4.2' nl c Refuse permission
' 4.6.5.3' nl > ' 9.4.3.2' nl c Duty
' 4.6.5.4' nl > ' 3.3.4.3' nl c Exempt
' 4.6.5.5' nl > ' 7.2.6.2' nl c Restrain
' 4.6.6' nl > ' 4.5.6' nl c Status
' 4.6.6.1' nl > ' 4.5.6.1' nl c High status
' 4.6.6.2' nl > ' 4.5.6.2' nl c Low status
' 4.6.7' nl > ' 4.6.6' nl c Government functions
' 4.6.7.1' nl > ' 4.6.6.1' nl c Police
' 4.6.7.1.1' nl > ' 4.6.6.1.1' nl c Arrest
' 4.6.7.1.2' nl > ' 4.6.6.1.2' nl c Informal justice
' 4.6.7.2' nl > ' 6.8.8' nl c Taxation
' 4.6.7.3' nl > ' 4.6.6.2' nl c Diplomacy
' 4.6.7.4' nl > ' 4.6.6.4' nl c Election
' 4.6.7.5' nl > ' 4.6.6.5' nl c Political party
' 4.6.8' nl > ' 4.5.4' nl c Submit to authority
' 4.6.8.1' nl > ' 4.5.4.3' nl c Serve
' 4.6.8.2' nl > ' 4.5.5' nl c Honor
' 4.6.8.2.1' nl > ' 4.5.5' nl c Posture of giving honor
' 4.6.8.2.2' nl > ' 4.5.5.1' nl c Title, name of honor
' 4.6.8.3' nl > ' 4.5.4.6' nl c Rebel against authority
' 4.6.8.4' nl > ' 4.5.5.2' nl c Lack respect
' 4.6.8.5' nl > ' 4.5.4.7' nl c Independent
' 4.6.9' nl > ' 4.6.7' nl c Region
' 4.6.9.1' nl > ' 4.6.7.1' nl c Country
' 4.6.9.2' nl > ' 4.6.7.2' nl c City
' 4.6.9.3' nl > ' 4.6.7.3' nl c Countryside
' 4.6.9.4' nl > ' 4.6.7.4' nl c Community
' 4.7.5' nl > ' 4.7.5' nl c Legal process
' 4.7.5.1' nl > ' 4.7.5.3' nl c Accuse, confront
' 4.7.5.2' nl > ' 4.8.2.4' nl c Defend
' 4.7.5.3' nl > ' 4.7.5.5' nl c Witness, testify
' 4.7.5.4' nl > ' 4.7.5.6' nl c Drop charges
' 4.7.5.5' nl > ' 4.7.5.7' nl c Take oath
' 4.7.5.6' nl > ' 4.7.5.8' nl c Vindicate
' 4.7.8.2' nl > ' 2.6.6.7' nl c Last will and testament
' 4.7.8.3' nl > ' 4.7.8.2' nl c Break a contract
' 4.8.1' nl > ' 4.8.2' nl c Fight
' 4.8.1.1' nl > ' 4.8.2.3' nl c Attack
' 4.8.1.2' nl > ' 2.5.3' nl c Harm, wound
' 4.8.1.3' nl > ' 4.8.2.3.1' nl c Ambush
' 4.8.1.4' nl > ' 4.8.2.6' nl c Riot
' 4.8.1.5' nl > ' 4.7.9.6' nl c Persecute
' 4.8.1.6' nl > ' 4.8.2.8' nl c Violent, fierce
' 4.8.1.7' nl > ' 4.8.2.9' nl c Enemy
' 4.8.2' nl > ' 4.8.2.4' nl c Defend from attack
' 4.8.2.1' nl > ' 4.8.2.4' nl c Repulse
' 4.8.2.2' nl > ' 4.8.2.5' nl c Retaliate
' 4.8.2.3' nl > ' 7.2.6.3' nl c Escape
' 4.8.2.4' nl > ' 7.2.6.4' nl c Set free
' 4.8.3' nl > ' 4.8.4' nl c Peace
' 4.8.3.1' nl > ' 4.8.4.1' nl c Rebuke
' 4.8.3.2' nl > ' 4.8.4.2' nl c Make an appeal
' 4.8.3.3' nl > ' 4.8.4.3' nl c Appease
' 4.8.3.4' nl > ' 4.8.4.4' nl c Negotiate
' 4.8.3.5' nl > ' 4.8.4.5' nl c Renounce claim, concede
' 4.8.3.6' nl > ' 4.8.4.6' nl c Repent
' 4.8.3.6.1' nl > ' 3.4.2.2' nl c Sorrow for wrong
' 4.8.3.6.2' nl > ' 3.4.2.2.1' nl c Shame
' 4.8.3.6.3' nl > ' 4.8.4.6.1' nl c Request forgiveness
' 4.8.3.7' nl > ' 4.8.4.7' nl c Forgive
' 4.8.3.8' nl > ' 4.8.4.8' nl c Make peace
' 4.8.3.8.1' nl > ' 4.8.4.8.1' nl c Stop fighting
' 4.8.3.9' nl > ' 4.8.4.9' nl c Reconcile
' 4.8.4' nl > ' 4.8.3' nl c War
' 4.8.4.1' nl > ' 4.8.3.1' nl c Defeat
' 4.8.4.2' nl > ' 4.8.3.2' nl c Win
' 4.8.4.3' nl > ' 4.8.3.3' nl c Lose
' 4.8.4.4' nl > ' 4.8.3.4' nl c Surrender
' 4.8.4.5' nl > ' 4.8.3.6.4' nl c Soldier
' 4.8.4.6' nl > ' 4.8.3.6.5' nl c Spy
' 4.8.4.7' nl > ' 4.8.3' nl c Casualty
' 4.8.4.7.1' nl > ' 4.4.3.7' nl c Survive
' 4.8.4.7.2' nl > ' 4.8.3.5' nl c Prisoner of war
' 4.8.4.8' nl > ' 4.8.3.6' nl c Military organizations
' 4.8.4.8.1' nl > ' 4.8.3.6.6' nl c Fort
' 4.8.4.9' nl > ' 4.8.3.7' nl c Weapon, Shoot
' 4.9.3' nl > ' 4.9.4' nl c Supernatural power
' 4.9.3.1' nl > ' 4.9.4' nl c Benevolent supernatural power
' 4.9.3.1.1' nl > ' 4.9.4' nl c Miracle
' 4.9.3.1.2' nl > ' 4.9.4.3' nl c Bless
' 4.9.3.2' nl > ' 4.9.4.1' nl c Malevolent supernatural power
' 4.9.3.2.1' nl > ' 4.9.4.2' nl c Demon possession
' 4.9.3.2.2' nl > ' 4.9.4.2' nl c Cast out demon
' 4.9.3.2.3' nl > ' 4.9.4.1' nl c Sorcery
' 4.9.3.2.4' nl > ' 4.9.4.4' nl c Curse
' 4.9.4' nl > ' 4.9.4.7' nl c Supernatural knowledge
' 4.9.4.1' nl > ' 4.9.4.6' nl c Prophecy
' 4.9.4.2' nl > ' 4.9.4.7' nl c Omen, divination
' 4.9.4.3' nl > ' 4.9.4.5' nl c Destiny
' 4.9.4.4' nl > ' 4.9.3' nl c Theology
' 4.9.4.5' nl > ' 4.9.3.1' nl c Sacred writings
' 5' nl > ' 6.5.1.1' nl c Home
' 5.1' nl > ' 6.5.2.7' nl c Rooms of a house
' 5.1.1' nl > ' 6.5.1.4' nl c Outside of a house
' 5.1.2' nl > ' 6.5.1.3' nl c Personal plot, property
' 5.1.3' nl > ' 5.1.1' nl c Furniture
' 5.1.3.1' nl > ' 5.1.1.1' nl c Table
' 5.1.3.2' nl > ' 5.1.1.2' nl c Chair
' 5.1.3.3' nl > ' 5.1.1.3' nl c Bed
' 5.1.3.4' nl > ' 5.1.1.4' nl c Cabinet
' 5.1.4' nl > ' 5.1' nl c Household tools
' 5.1.5' nl > ' 5.1.2' nl c Household decorations
' 5.2.1.2.1' nl > ' 5.2.1.2' nl c Allow food to ripen
' 5.2.1.2.2' nl > ' 5.2.1.2.1' nl c Remove shell, skin
' 5.2.1.2.3' nl > ' 5.2.1.2.2' nl c Pound in mortar and pestle
' 5.2.1.2.4' nl > ' 5.2.1.2.3' nl c Grind flour
' 5.2.1.2.5' nl > ' 5.2.1.2' nl c Cut up ingredients
' 5.2.1.3' nl > ' 5.2.1.2' nl c Recipe
' 5.2.1.4' nl > ' 5.2.1.3' nl c Cooking utensils
' 5.2.1.5' nl > ' 5.2.1.4' nl c Food storage
' 5.2.1.6' nl > ' 5.2.1.5' nl c Serve food
' 5.2.2.1' nl > ' 5.2.2.2' nl c Meal
' 5.2.2.2' nl > ' 5.2.2.3' nl c Feast
' 5.2.2.3' nl > ' 5.2.2.4' nl c Manner of eating
' 5.2.2.4' nl > ' 2.3.3' nl c Taste of food
' 6.1.1.1' nl > ' 4.5.4.3' nl c Slave, servant
' 6.1.1.2' nl > ' 6.1.1.1' nl c Expert
' 6.1.2.2.1' nl > ' 6.1.2.2.3' nl c Available
' 6.1.2.2.2' nl > ' 6.1.2.2.4' nl c Use up
' 6.1.2.2.3' nl > ' 6.1.2.2.5' nl c Take care of something
' 6.1.2.2.4' nl > ' 6.1.2.2.6' nl c Waste
' 6.1.2.3.1' nl > ' 6.1.2.3.2' nl c Work hard
' 6.1.2.3.2' nl > ' 6.1.2.3.1' nl c Careful
' 6.1.2.3.4' nl > ' 3.3.1.6' nl c Persevere
' 6.1.2.3.5' nl > ' 6.1.2.3.4' nl c Power, force
' 6.1.2.3.7' nl > ' 6.1.2.3.3' nl c Busy
' 6.1.2.3.8' nl > ' 6.1.2.3.5' nl c Complete, finish
' 6.1.2.4.2' nl > ' 9.4.2.2' nl c Incapable
' 6.1.2.4.3' nl > ' 6.1.2.4.2' nl c Lazy
' 6.1.2.4.4' nl > ' 6.1.2.4.3' nl c Give up
' 6.2.1.2' nl > ' 6.2.1.7' nl c Growing trees
' 6.2.1.3' nl > ' 6.2.1.6' nl c Growing flowers
' 6.2.5.2' nl > ' 6.2.4.2' nl c Uproot plants
' 6.2.5.3' nl > ' 6.2.5.2' nl c Crop failure
' 6.2.5.4' nl > ' 6.2.5.3' nl c Gather wild plants
' 6.2.5.5' nl > ' 6.2.5.4' nl c Plant product
' 6.5.1.1' nl > ' 6.5.1.2' nl c Types of houses
' 6.7.3' nl > ' 6.7.1.2' nl c Digging tool
' 6.7.4' nl > ' 6.7.3' nl c Carrying tool
' 6.7.5' nl > ' 7.2.1.1' nl c Walking stick
' 6.7.6' nl > ' 6.7.1.1' nl c Poking tool
' 6.8.1.2' nl > ' 8.1.7' nl c Have sufficient
' 6.8.1.3' nl > ' 8.1.7.1' nl c Have extra
' 6.8.1.4' nl > ' 6.8.1.2' nl c Wealthy
' 6.8.1.5' nl > ' 8.1.7.2' nl c Have insufficient
' 6.8.1.6' nl > ' 6.8.1.3' nl c Poor
' 6.8.1.7' nl > ' 6.8.1.4' nl c Store wealth
' 6.8.1.8' nl > ' 6.8.1.5' nl c Property
' 6.8.2.3' nl > ' 2.6.6.7' nl c Inherit
' 6.8.2.4' nl > ' 6.8.2.3' nl c Lose wealth
' 6.8.2.5' nl > ' 6.8.2.4' nl c Frugal
' 6.8.2.6' nl > ' 6.8.2.5' nl c Greedy
' 6.8.9.4' nl > ' 6.8.9.1' nl c Embezzle
' 6.8.9.5' nl > ' 6.8.9.4' nl c Take by force
' 6.8.9.6' nl > ' 6.8.9' nl c Counterfeit
' 6.8.9.7' nl > ' 6.8.9.4' nl c Booty
' 6.8.9.8' nl > ' 6.8.9.5' nl c Bribe
' 7.2.1.2' nl > ' 7.2.1.1.1' nl c Run
' 7.2.1.3' nl > ' 7.2.1.1.2' nl c Crawl
' 7.2.1.4' nl > ' 7.2.1.1.3' nl c Jump
' 7.2.1.5' nl > ' 7.2.1.2' nl c Move quickly
' 7.2.1.5.1' nl > ' 7.2.1.2.1' nl c Move slowly
' 7.2.1.6' nl > ' 3.3.1.6' nl c Move purposefully
' 7.2.1.6.1' nl > ' 7.2.1.3' nl c Wander
' 7.2.1.7' nl > ' 7.2.1.4' nl c Graceful
' 7.2.1.7.1' nl > ' 7.2.1.4.1' nl c Clumsy
' 7.2.1.8' nl > ' 7.2.1.5' nl c Walk with difficulty
' 7.2.1.8.1' nl > ' 7.2.1.5.1' nl c Slip, slide
' 7.2.1.9' nl > ' 7.2.1.6' nl c Steady, unsteady
' 7.2.1.9.1' nl > ' 7.2.1.6.1' nl c Balance
' 7.2.4' nl > ' 7.2.5' nl c Accompany
' 7.2.4.1' nl > ' 7.2.5.1' nl c Go first
' 7.2.4.2' nl > ' 7.2.5.2' nl c Follow
' 7.2.4.3' nl > ' 7.2.5.3' nl c Guide
' 7.2.5' nl > ' 7.2.6' nl c Flee, pursue
' 7.2.5.1' nl > ' 7.3.3.4' nl c Chase away
' 7.2.6' nl > ' 7.2.4' nl c Travel
' 7.2.6.1' nl > ' 7.2.4.1' nl c Travel by land
' 7.2.6.1.1' nl > ' 7.2.4.1.1' nl c Vehicle
' 7.2.6.2' nl > ' 7.2.4.2' nl c Travel by water
' 7.2.6.2.1' nl > ' 7.2.4.2.1' nl c Boat
' 7.2.6.2.2' nl > ' 7.2.4.2.2' nl c Swim
' 7.2.6.2.3' nl > ' 7.2.4.2.3' nl c Dive
' 7.2.6.3' nl > ' 7.2.4.3' nl c Travel by air
' 7.2.6.4' nl > ' 7.2.4.4' nl c Travel in space
' 7.2.6.5' nl > ' 7.2.4.5' nl c Move to a new house
' 7.2.6.6' nl > ' 7.2.4.8' nl c Map
' 7.2.8' nl > ' 7.2.4.7' nl c Lose your way
' 7.2.9' nl > ' 7.2.8' nl c Send someone
' 7.3.3.4' nl > ' 7.4.1' nl c Give, hand to
' 7.3.3.5' nl > ' 7.4.2' nl c Receive
' 7.3.3.6' nl > ' 7.4.4' nl c Distribute
' 7.3.9' nl > ' 7.4.5' nl c Keep something
' 7.3.9.1' nl > ' 7.4.5.1' nl c Leave something
' 7.3.9.2' nl > ' 7.4.5.2' nl c Throw away
' 7.4' nl > ' 7.5' nl c Arrange, organize
' 7.4.1' nl > ' 7.5.1' nl c Gather
' 7.4.1.1' nl > ' 7.5.1.1' nl c Separate, scatter
' 7.4.1.2' nl > ' 7.5.1.2' nl c Include
' 7.4.1.3' nl > ' 7.5.1.3' nl c Special
' 7.4.2' nl > ' 7.5.2' nl c Join
' 7.4.2.1' nl > ' 7.5.2' nl c Joint
' 7.4.2.2' nl > ' 7.5.2.2' nl c Cohere
' 7.4.2.3' nl > ' 7.5.2.4' nl c Come apart
' 7.4.2.4' nl > ' 7.5.2.4' nl c Remove part of something
' 7.4.2.5' nl > ' 7.5.2.4' nl c Take apart
' 7.4.2.6' nl > ' 7.5.2' nl c Reunite
' 7.4.3' nl > ' 7.5.3' nl c Mix
' 7.4.3.1' nl > ' 7.5.3.1' nl c Pure, unmixed
' 7.4.4' nl > ' 7.5.4' nl c Tie
' 7.4.4.1' nl > ' 7.5.4' nl c Untie
' 7.4.4.2' nl > ' 7.5.4.1' nl c Rope, string
' 7.4.4.3' nl > ' 6.7.5' nl c Tape
' 7.4.4.4' nl > ' 7.5.4.2' nl c Tangle
' 7.4.4.5' nl > ' 7.3.7.2' nl c Wrap
' 7.4.5' nl > ' 7.5.5.1' nl c Disorganize
' 7.4.6' nl > ' 7.5.6' nl c Substitute
' 7.4.7' nl > ' 7.5.7' nl c Multiple things moving
' 7.4.8' nl > ' 7.5.8' nl c Simple, complicated
' 7.4.9' nl > ' 8.4.5.1' nl c Order, sequence
' 7.5' nl > ' 7.6' nl c Hide
' 7.5.1' nl > ' 7.6.1' nl c Search
' 7.5.2' nl > ' 7.6.2' nl c Find
' 7.5.3' nl > ' 7.6.3' nl c Lose, misplace
' 7.6' nl > ' 7.7' nl c Physical impact
' 7.6.1' nl > ' 7.7.1' nl c Hit
' 7.6.2' nl > ' 7.7.1' nl c Bounce
' 7.6.3' nl > ' 7.7.2' nl c Aim at a target
' 7.6.4' nl > ' 7.7.3' nl c Kick
' 7.6.5' nl > ' 7.7.4' nl c Press
' 7.6.6' nl > ' 7.7.5' nl c Rub
' 7.6.7' nl > ' 7.7.6' nl c Grind
' 7.6.8' nl > ' 7.7.7' nl c Mark
' 7.7' nl > ' 7.8' nl c Divide into pieces
' 7.7.1' nl > ' 7.8.1' nl c Break
' 7.7.2' nl > ' 7.8.2' nl c Crack
' 7.7.3' nl > ' 7.8.3' nl c Cut
' 7.7.4' nl > ' 7.8.4' nl c Tear, rip
' 7.7.5' nl > ' 7.8.5' nl c Make hole, opening
' 7.7.6' nl > ' 7.8.6' nl c Dig
' 7.7.7' nl > ' 7.9.1' nl c Damage
' 7.7.8' nl > ' 7.9.2' nl c Tear down
' 7.7.9' nl > ' 7.9.3' nl c Destroy
' 7.8' nl > ' 7.9.4' nl c Repair
' 8.1.1' nl > ' 8.1.2' nl c Count
' 8.1.1.1' nl > ' 8.1.2.1' nl c Arithmetic
' 8.1.1.2' nl > ' 8.1.2.2' nl c Add
' 8.1.1.3' nl > ' 8.1.2.3' nl c Subtract
' 8.1.1.4' nl > ' 8.1.2.4' nl c Multiply
' 8.1.1.5' nl > ' 8.1.2.5' nl c Divide
' 8.1.2' nl > ' 8.1.1' nl c Number
' 8.1.2.1' nl > ' 8.1.1.1' nl c Cardinal numbers
' 8.1.2.2' nl > ' 8.1.1.2' nl c Ordinal numbers
' 8.1.2.3' nl > ' 8.1.1.3' nl c Number of times
' 8.1.2.4' nl > ' 8.1.1.4' nl c Multiples
' 8.1.2.5' nl > ' 8.1.1.5' nl c Numbered collective
' 8.1.2.6' nl > ' 8.1.1.6' nl c Fraction
' 8.1.2.7' nl > ' 8.4.5.1' nl c Sequence
' 8.1.3' nl > ' 8.1.3.1' nl c Many
' 8.1.3.1' nl > ' 8.1.3.2' nl c Few
' 8.1.3.2' nl > ' 8.1.3.3' nl c Group of things
' 8.1.4.4' nl > ' 8.1.5.9' nl c Average
' 8.1.5.2' nl > ' 8.3.5.2.4' nl c Other
' 8.1.5.3' nl > ' 8.1.7.4' nl c Remainder
' 8.1.5.4' nl > ' 8.1.5.6' nl c Almost
' 8.1.5.5' nl > ' 8.1.5.3' nl c Both
' 8.1.5.6' nl > ' 8.1.5.7' nl c Only
' 8.1.7' nl > ' 8.1.3.1' nl c Much, little
' 8.1.8' nl > ' 9.3.1' nl c Degree
' 8.1.8.1' nl > ' 9.3.2' nl c Completely
' 8.2' nl > ' 8.2.8' nl c Measure
' 8.2.1' nl > ' 8.2.9' nl c Weight
' 8.2.1.1' nl > ' 8.2.9.1' nl c Heavy
' 8.2.1.2' nl > ' 8.2.9.2' nl c Light in weight
' 8.2.2.1' nl > ' 8.2.2' nl c Long
' 8.2.2.2' nl > ' 8.2.2.1' nl c Short
' 8.2.2.3' nl > ' 8.2.2.2' nl c Tall
' 8.2.2.4' nl > ' 8.2.4' nl c Wide
' 8.2.2.5' nl > ' 8.2.4.1' nl c Narrow
' 8.2.2.6' nl > ' 8.2.6.5' nl c Deep, shallow
' 8.2.3' nl > ' 8.5.4' nl c Area
' 8.2.4' nl > ' 8.2.5.1' nl c Volume
' 8.2.4.1' nl > ' 8.2' nl c Big
' 8.2.4.2' nl > ' 8.2.1' nl c Small
' 8.2.4.3' nl > ' 8.2' nl c Get larger
' 8.2.4.4' nl > ' 8.2.1' nl c Get smaller
' 8.2.4.5' nl > ' 8.2.3' nl c Fat, thick
' 8.2.4.6' nl > ' 8.2.3.1' nl c Thin
' 8.2.4.7' nl > ' 8.1.8' nl c Full
' 8.2.4.8' nl > ' 8.1.8.1' nl c Empty
' 8.2.4.9' nl > ' 8.1.8' nl c Overflowing
' 8.2.5' nl > ' 8.2.7' nl c Fit, size
' 8.2.5.1' nl > ' 8.2.7.1' nl c Tight, loose
' 8.2.5.2' nl > ' 8.2.7.3' nl c Wedged in, stuck
' 8.3.1.8' nl > ' 8.3.1.8.1' nl c Symmetrical
' 8.3.2.3.2' nl > ' 8.3.2.3' nl c Sharpen
' 8.3.2.5' nl > ' 8.3.6.5' nl c Soft, flimsy
' 8.3.2.6' nl > ' 8.3.6.2' nl c Hard, firm
' 8.3.2.7' nl > ' 8.3.2.5' nl c Furrow
' 8.3.3.3.8' nl > ' 8.3.3.3' nl c Colorless
' 8.3.3.4' nl > ' 2.3.1.5' nl c Visible
' 8.3.3.5' nl > ' 2.3.1.5.1' nl c Appear
' 8.3.3.6' nl > ' 2.3.1.6' nl c Transparent
' 8.3.3.7' nl > ' 2.3.1.7' nl c Reflect
' 8.3.4.1' nl > ' 8.3.4' nl c Hot
' 8.3.4.2' nl > ' 8.3.4' nl c Warm
' 8.3.4.3' nl > ' 8.3.4.1' nl c Cold
' 8.3.4.4' nl > ' 8.3.4' nl c Change temperature
' 8.3.5' nl > ' 8.3.7.8' nl c Decay
' 8.3.5.1' nl > ' 8.3.7.8.1' nl c Eaten by rust, insects
' 8.3.5.2' nl > ' 7.9.3' nl c Ruined, spoiled
' 8.3.5.3' nl > ' 8.3.7.8.3' nl c Garbage
' 8.3.5.4' nl > ' 8.3.7.8.4' nl c Preserve
' 8.3.6' nl > ' 8.3.5' nl c Class
' 8.3.6.1' nl > ' 8.3.5.1' nl c Nature, character
' 8.3.6.2' nl > ' 8.3.5.2' nl c Compare
' 8.3.6.2.1' nl > ' 8.3.5.2.1' nl c Same
' 8.3.6.2.2' nl > ' 8.3.5.2.2' nl c Like, similar
' 8.3.6.2.3' nl > ' 8.3.5.2.3' nl c Different
' 8.3.6.2.4' nl > ' 8.3.5.3' nl c Common
' 8.3.6.2.5' nl > ' 8.3.5.3.3' nl c Unique
' 8.3.6.2.6' nl > ' 8.3.5.3.1' nl c Usual
' 8.3.6.2.7' nl > ' 8.3.5.3.2' nl c Unusual
' 8.3.6.2.8' nl > ' 8.3.5.3.4' nl c Strange
' 8.3.6.3' nl > ' 8.3.5.4' nl c Pattern, model
' 8.3.6.4' nl > ' 8.3.5.5' nl c Imitate
' 8.3.7' nl > ' 8.3.6' nl c Material composition
' 8.3.7.1' nl > ' 8.3.6.1' nl c Strong, brittle
' 8.3.7.2' nl > ' 8.3.6.2' nl c Hard
' 8.3.7.3' nl > ' 8.3.6.3' nl c Stiff, flexible
' 8.3.7.4' nl > ' 8.3.6.4' nl c Dense
' 8.3.8' nl > ' 8.3.7' nl c Good
' 8.3.8.1' nl > ' 8.3.7.1' nl c Bad
' 8.3.8.2' nl > ' 8.3.7.2' nl c Better, surpass
' 8.3.8.2.1' nl > ' 8.3.7.2.1' nl c Worse, lesser
' 8.3.8.3' nl > ' 8.3.7.3' nl c Perfect
' 8.3.8.4' nl > ' 8.3.7.4' nl c Mediocre
' 8.3.8.5' nl > ' 8.3.7.5' nl c Important
' 8.3.8.5.1' nl > ' 8.3.7.5.1' nl c Basic
' 8.3.8.6' nl > ' 8.3.7.6' nl c Improve
' 8.3.8.7' nl > ' 8.3.7.7' nl c Suitable
' 8.3.8.8' nl > ' 8.3.7.8.2' nl c Blemish
' 8.3.8.9' nl > ' 8.3.7.9' nl c Value
' 8.3.9' nl > ' 2.3.1.8' nl c Appearance
' 8.3.9.1' nl > ' 2.3.1.8.1' nl c Beautiful, ugly
' 8.3.9.2' nl > ' 8.3.8.2' nl c Glory
' 8.3.9.3' nl > ' 8.3.8.1' nl c Simple, plain
' 8.4.1.2.1' nl > ' 8.4.1.2.2' nl c Days relative to each other
' 8.4.2' nl > ' 8.4.1.2.3' nl c Time of the day
' 8.4.2.1' nl > ' 8.4.1.2.3' nl c Just before dawn
' 8.4.2.2' nl > ' 8.4.1.2.3' nl c Dawn
' 8.4.2.3' nl > ' 8.4.1.2.3' nl c Morning
' 8.4.2.4' nl > ' 8.4.1.2.3' nl c Noon
' 8.4.2.5' nl > ' 8.4.1.2.3' nl c Afternoon
' 8.4.2.6' nl > ' 8.4.1.2.3' nl c Sunset
' 8.4.2.7' nl > ' 8.4.1.2.3' nl c Evening
' 8.4.2.8' nl > ' 8.4.1.2.1' nl c Night
' 8.4.2.9' nl > ' 8.4.1.2.3' nl c Midnight
' 8.4.5.1.1' nl > ' 8.4.5.2' nl c Happen before
' 8.4.5.1.2' nl > ' 8.4.5.2.2' nl c Happen at same time
' 8.4.5.1.3' nl > ' 8.4.5.2.1' nl c Happen after
' 8.4.5.1.4' nl > ' 8.4.5.1.5' nl c Regular
' 8.4.5.2' nl > ' 8.4.5.1' nl c Temporal order
' 8.4.5.2.1' nl > ' 8.4.5.1.2' nl c Happen first
' 8.4.5.2.2' nl > ' 8.4.5.1.3' nl c Happen next
' 8.4.5.2.3' nl > ' 8.4.5.1.4' nl c Happen last
' 8.4.5.3' nl > ' 8.4.5.3.2' nl c Punctuality
' 8.4.6.1.1' nl > ' 8.4.6.1.2' nl c Stop, end
' 8.4.6.4.4' nl > ' 8.4.6.1.4' nl c Until
' 8.4.6.4.5' nl > ' 8.4.6.4.4' nl c Immediate
' 8.4.6.5.1' nl > ' 8.4.6.5.3' nl c New
' 8.4.7' nl > ' 8.4.2' nl c Take time
' 8.4.7.1' nl > ' 8.4.7' nl c Continue, endure
' 8.4.7.2' nl > ' 8.4.7.1' nl c Interrupt
' 8.4.7.3' nl > ' 8.4.7.2' nl c Start again
' 8.4.7.4' nl > ' 8.4.2.1' nl c A short time
' 8.4.7.5' nl > ' 8.4.2.2' nl c A long time
' 8.4.7.6' nl > ' 8.4.8.3' nl c Sudden
' 8.4.7.7' nl > ' 8.4.2.3' nl c Forever
' 8.4.7.8' nl > ' 8.4.2.4' nl c Temporary
' 8.4.7.9' nl > ' 8.4.7.3' nl c Interval
' 8.5.1.3.1' nl > ' 8.5.1.3.2' nl c Under, below
' 8.5.1.4' nl > ' 8.2.6.3' nl c High
' 8.5.1.4.1' nl > ' 8.2.6.4' nl c Low
' 8.5.1.5' nl > ' 8.5.1.4' nl c Inside
' 8.5.1.5.1' nl > ' 8.5.1.4.1' nl c Outside
' 8.5.1.6' nl > ' 8.2.6' nl c Distance
' 8.5.1.6.1' nl > ' 8.5.1.5' nl c Touching, contact
' 8.5.1.6.2' nl > ' 8.5.1.5.1' nl c Next to
' 8.5.1.6.3' nl > ' 8.2.6.2' nl c Near
' 8.5.1.6.4' nl > ' 8.2.6.1' nl c Far
' 8.5.1.7' nl > ' 8.5.1.6' nl c Across
' 8.5.1.8' nl > ' 8.6.5' nl c Center
' 8.5.1.9' nl > ' 8.5.1.7' nl c Indefinite location
' 8.5.2.1' nl > ' 8.5.2.6' nl c From, to
' 8.5.2.2' nl > ' 8.5.2.7' nl c Toward, away from
' 8.5.2.3' nl > ' 8.5.2.8' nl c North, south, east, west
' 8.5.2.4' nl > ' 8.5.2.3' nl c Right, left
' 8.5.4' nl > ' 8.5.4.1' nl c Vicinity
' 8.5.4.1' nl > ' 8.5.4.2' nl c Occupy an area
' 8.5.4.2' nl > ' 8.5.4.3' nl c Space, room
' 8.5.4.3' nl > ' 8.5.4.4' nl c Interval, space
' 9.1.1.1' nl > ' 9.1.1.2' nl c Become, change state
' 9.1.1.2' nl > ' 7.4' nl c Have
' 9.1.2.4' nl > ' 9.1.2.6' nl c Change something
' 9.1.6' nl > ' 9.1.1.3' nl c Of
' 9.3' nl > ' 9.1.2.7' nl c Propositions
' 9.3.1' nl > ' 9.1.2.7' nl c Event propositions
' 9.3.1.1' nl > ' 9.1.2.7' nl c Event--activity
' 9.3.1.2' nl > ' 9.1.2.7' nl c Event--experience
' 9.3.1.3' nl > ' 9.1.2.7' nl c Event--cognition
' 9.3.1.4' nl > ' 9.1.2.2' nl c Event--reaction
' 9.3.1.5' nl > ' 9.1.2.7' nl c Event--expression
' 9.3.1.6' nl > ' 9.1.2.3' nl c Event--creation
' 9.3.1.7' nl > ' 9.1.2.7' nl c Event--process
' 9.3.2' nl > ' 9.1.1.1' nl c Existential
' 9.3.3' nl > ' 9.6' nl c Association Propositions
' 9.3.3.1' nl > ' 4.1' nl c Social relationship
' 9.3.3.1.1' nl > ' 4.1.9' nl c Kinship
' 9.3.3.1.2' nl > ' 4.2.1.8.3' nl c Affiliation
' 9.3.3.2' nl > ' 6.8.1.1' nl c Ownership
' 9.3.3.3' nl > ' 8.3.5' nl c Classification
' 9.3.3.4' nl > ' 8.1.6.1' nl c Partitive
' 9.3.3.5' nl > ' 8.5.6' nl c Containership
' 9.3.3.6' nl > ' 6.1.2.2' nl c Usage
' 9.3.3.7' nl > ' 3.5.1.2.9' nl c Depiction
' 9.3.3.8' nl > ' 8.5' nl c Location
' 9.3.3.8.1' nl > ' 8.4' nl c Temporal location
' 9.3.3.8.2' nl > ' 8.5' nl c Spatial location
' 9.3.4' nl > ' 8.1' nl c Quantity propositions
' 9.3.4.1' nl > ' 8.1.1' nl c Enumeration
' 9.3.4.2' nl > ' 8.1' nl c Quantification
' 9.3.4.3' nl > ' 8.2.8' nl c Measurement
' 9.3.4.4' nl > ' 8.1' nl c Proportion
' 9.3.4.5' nl > ' 8.1.6.1' nl c Subdivision
' 9.3.4.6' nl > ' 8.1.2.1' nl c Summation
' 9.3.4.7' nl > ' 8.1.3' nl c Plurality
' 9.3.4.8' nl > ' 8.4.5.1' nl c Order
' 9.3.5' nl > ' 9.1.1.4' nl c Attribution
' 9.3.5.1' nl > ' 9.3.5' nl c Attribution of an attribute
' 9.3.5.2' nl > ' 9.3' nl c Intensity of an attribute
' 9.3.5.3' nl > ' 9.3.1' nl c Degree on a scale
' 9.3.6' nl > ' 9.1.1' nl c Identificational propositions
' 9.3.6.1' nl > ' 9.1.1' nl c Identification
' 9.3.6.2' nl > ' 9.2.3.5' nl c Specification
' 9.3.6.3' nl > ' 8.3.5.2.3' nl c Differentiation
' 9.4.1.2.1' nl > ' 9.3.4' nl c Do intensely
' 9.4.2.2' nl > ' 6.1.2.1' nl c Attempt
' 9.4.2.3' nl > ' 8.1.7.3' nl c Requisite resources
' 9.4.2.4' nl > ' 6.1.2.3.5' nl c Achievement
' 9.4.3.1' nl > ' 9.4.4' nl c Epistemic moods
' 9.4.3.1.1' nl > ' 9.4.4.4' nl c Possible
' 9.4.3.1.2' nl > ' 9.4.4.3' nl c Probable
' 9.4.3.1.3' nl > ' 9.4.4.2' nl c Certain, sure
' 9.4.3.1.4' nl > ' 9.4.4.5' nl c Uncertain
' 9.4.3.1.5' nl > ' 9.4.4.7' nl c Almost not
' 9.4.3.2' nl > ' 9.4.3.1' nl c Imperative
' 9.4.3.2.1' nl > ' 9.4.3.2' nl c Hortative
' 9.4.3.2.2' nl > ' 9.4.2.3' nl c Necessary
' 9.4.3.3' nl > ' 9.4.7' nl c Subordinating
' 9.4.3.4' nl > ' 9.6.2.8' nl c Conditional sentences
' 9.4.3.5' nl > ' 9.4.8' nl c Adverbial clauses
' 9.4.3.6' nl > ' 9.4.3.3' nl c Interrogative
' 9.4.3.7' nl > ' 9.4.4.6.1' nl c Suppose
' 9.4.3.8' nl > ' 9.4.4.6.3' nl c Seem
' 9.4.4' nl > ' 9.4.5' nl c Evidentials
' 9.4.4.1' nl > ' 9.4.5.1' nl c Evaluator
' 9.4.5' nl > ' 9.4.6' nl c Affirmation
' 9.4.5.1' nl > ' 9.4.6.1' nl c Negation
' 9.4.5.2' nl > ' 9.4.6.2' nl c Markers expecting an affirmative answer
' 9.4.5.3' nl > ' 9.4.6.3' nl c Markers expecting a negative answer
' 9.5.1.2' nl > ' 3.5.1.2.9' nl c Topic
' 9.5.1.3' nl > ' 9.5.1.2' nl c Instrument
' 9.5.1.4' nl > ' 9.5.1.3' nl c Means
' 9.5.1.5' nl > ' 9.5.1.4' nl c Manner
' 9.5.1.6' nl > ' 9.5.1.5' nl c Attendant circumstances
' 9.5.1.7' nl > ' 8.4' nl c Temporal location of an event
' 9.5.1.8' nl > ' 9.5.1.6' nl c Spatial location of an event
' 9.5.1.8.1' nl > ' 9.5.1.6.1' nl c Source
' 9.5.1.8.2' nl > ' 9.5.1.6.2' nl c Path
' 9.5.1.8.3' nl > ' 9.5.1.6.3' nl c Goal of movement
' 9.5.1.9' nl > ' 9.6' nl c Logical location
' 9.5.2.1' nl > ' 9.5.2.1' nl c Collectivity
' 9.5.2.1.1' nl > ' 9.5.2.2' nl c Accompaniment
' 9.5.2.2' nl > ' 9.6.1.7' nl c Isolation
' 9.5.2.3' nl > ' 9.5.2.4' nl c Reciprocal
' 9.5.2.4' nl > ' 9.5.2.5' nl c Distributive
' 9.5.2.5' nl > ' 8.1.1.3' nl c Quantity of an event
' 9.5.2.6' nl > ' 8.4.6.6.3' nl c Frequency
' 9.5.2.7' nl > ' 9.6.1.1' nl c Duplication
' 9.5.2.8' nl > ' 8.4.6.6.1' nl c Repetition
' 9.5.2.9' nl > ' 9.6.1.1' nl c Semantic addition
' 9.5.3' nl > ' 4.3.4.2' nl c Enabling propositions
' 9.5.3.1' nl > ' 9.6.2.5' nl c Causer
' 9.5.3.2' nl > ' 4.3.4.2' nl c Helper
' 9.5.3.3' nl > ' 4.3.4.2.1' nl c Hinderer
' 9.5.3.4' nl > ' 3.3.4.4' nl c Preventer
' 9.5.3.5' nl > ' 3.3.4.1' nl c Authorizer
' 9.5.3.6' nl > ' 4.6.6.3' nl c Representative
' 9.5.3.7' nl > ' 8.4.6.1' nl c Start something
' 9.5.4' nl > ' 9.5.3' nl c Patient-related cases
' 9.5.4.1' nl > ' 9.5.3.1' nl c Beneficiary of a patient
' 9.5.4.2' nl > ' 9.5.3.2' nl c Recipient of a patient
' 9.5.4.3' nl > ' 9.5.3.3' nl c Accompaniment of a patient
' 9.5.4.4' nl > ' 8.5' nl c Spatial location of a patient
' 9.5.5' nl > ' 9.5' nl c Tertiary-related cases
' 9.5.5.1' nl > ' 8.1.5.8.1' nl c Approximation
' 9.5.6' nl > ' 9.5' nl c Tertiary cases
' 9.6.1.9' nl > ' 8.5.1.2.2' nl c Mediation
' 9.6.2.5.1' nl > ' 9.6.2.5.2' nl c Without cause
' 9.6.2.7.2' nl > ' 9.6.2.7' nl c Negative purpose
' 9.7.1' nl > ' 9.7.1.1' nl c Personal names
' 9.7.3' nl > ' 9.7.3.1' nl c Names of animals
