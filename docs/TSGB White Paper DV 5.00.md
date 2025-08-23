TwinScroll Grid Balancer (TSGB) – Document Version 5.0
Envisioned by: M. Shirley.
Date: August 9th, 2025.

THIS WHITEPAPER IS LENGTHY BECAUSE THE 7 P'S RULE.

PRIOR, PREPERATION AND PLANNING PREVENTS PISS POOR PERFORMANCE.

And because i believe in providing intent as context and facts as anchors. Lets put sir isac newton back in the drivers seat.


 Table of Contents

1. [Introduction & Abstract](introduction--abstract)
2. [Background: The Grid Stability Challenge](background-the-grid-stability-challenge)
3. [TSGB Concept Overview](tsgb-concept-overview)
    - 3.1 [Core Architecture](31-core-architecture)
    - 3.2 [Key Features and Innovations](32-key-features-and-innovations)
    - 3.3 [Modularity, Configurability, and Deployment](33-modularity-configurability-and-deployment)
    - 3.4 [Physical Footprint, Power Density, and Site Efficiency](34-physical-footprint-power-density-and-site-efficiency)
    - 3.5 [Container-Based Containment Building Concept](35-container-based-containment-building-concept)
4. [Technical Deep Dive](technical-deep-dive)
    - 4.1 [Mechanical Inertia and Ride-Through](41-mechanical-inertia-and-ride-through)
    - 4.2 [Automated Manual Transmission (AMT)](42-automated-manual-transmission-amt)
    - 4.3 [DC Supply Blending](43-dc-supply-blending)
    - 4.4 [Grid-Forming and HVDC Anchor Strategy](44-grid-forming-and-hvdc-anchor-strategy)
    - 4.5 [Black Start and Grid Deadlift Protocols](45-black-start-and-grid-deadlift-protocols)
5. [Fleet Sizing, Deployment, and Scenarios](fleet-sizing-deployment-and-scenarios)
    - 5.1 [Fleet Design and Composition](51-fleet-design-and-composition)
    - 5.2 [Deployment Strategy](52-deployment-strategy)
    - 5.3 [Scenario Analysis: Historical UK Grid Events](53-scenario-analysis-historical-uk-grid-events)
6. [Comparative Analysis: TSGB vs. Other Technologies](comparative-analysis-tsgb-vs-other-technologies)
7. [Business Case, Revenue, and Maintenance](business-case-revenue-and-maintenance)
8. [Applications and Opportunities](applications-and-opportunities)
9. [Technical Gaps, Research Needs, and Honest Assessment](technical-gaps-research-needs-and-honest-assessment)
11. [Glossary](glossary)
12. [References](references)
13. [Conclusion](conclusion)



This started with a single simple question: 
Where did all the inertia go? 

Boy, oh boy, how I failed to realize how deep this rabbit hole goes.


Why name it twin scroll grid balancer TSGB. 
Really simply put i wanted GB in the name, why not im british, and in my mind when i started this journey it made sense to call it twin scroll, before i fleshed this out better in the early stages i envisaged a rotor being driven from many smaller motors and direct drive couplings, then i did some DC motor research, and that went right out the window. So the TWIN was for Input, Scroll was for the shaft where i envisaged initially (having no clue about inertial mass, thinking i'd need 100 ton), shafts laid side by side and linked, allowing for massive energy storage, but turns out 10 ton is a more than sufficient for me and my idea, but the "scrolls" side by side could actually be done, it's just ring gear. 

Twin (Input), Scroll (Rotating shaft) Grid (Great) Balancer (Britain).

It's a horrible name, but it's stuck, it does a great job at setting this up for massive miss interpretation.




 1.0 Introduction & Abstract

- The TwinScroll Grid Balancer (TSGB) is a novel, highly modular grid-support technology.
- Designed to passively and actively stabilize electrical networks.
- Combines mechanical inertia, reactive power generation, and real power injection into a single, flexible platform.
- Unlike traditional large-scale inertia systems or battery-based stabilization solutions, the TSGB is distributed, scalable, and modular.
- Emphasizes the aggregation of many small units rather than reliance on a few critical assets.

 1.1 Frequently Asked Questions (FAQ)

Q: What is the TSGB NOT?  
- It's not a flywheel — it's a fly shaft, and it's more flexible than you think. Get "flywheel" out of your head, but you can hang on to the general principles. There are no massive 7k to 20k RPM disks begging for an excuse to decapitate and scalpe the planet, flywheels in their traditional form terrify me, but their concept is sound, and scales down very nicely. Since we only need to provide ride-through, we don’t need a billion revs at 20 tons, encased in a nuclear submarine pen, and bearings from NASA Engineering. It operates like a flywheel, but it’s not a flywheel — the shaft itself is the mass. No disks, no added weight, no welds, no bolts, no need for extreme precision. Keep it simple, stupid.



Q: What are the hardware and technical challenges?  
- All parts are commercial off-the-shelf, simple, and reliable mechanical machines—no exotic or complex components. 10-ton shafts at 3000 RPM are routinely spun safely with good engineering. Concrete and rebar are strong and affordable.



Q: Is the design footprint unrealistic?  
- No. The quoted size is intentionally overkill for safety and maintenance. The system can fit into three 40ft High Cube containers end-to-end (120 ft total), with room for access and repair.



Q: Is maintenance difficult?  
- No. Maintenance is minimal: just bearings and brushes. Overkill is underrated—spend on quality bearings. Brushes can be made large and durable. The chamber is fixed-size, so wear is slow and predictable.

Q: What about bearing failure.
Bearings have a great proxy for health, temprature, if any bearing temp > 75c a shutdown would be triggered

Q; Whats the worst case failure
You cheap out on shaft design and underrate it. Catastropic shaft failure. The continment vessle as described  would mearly be cracked

Q: How do you handle fires?  
- It’s a sealed box — you use CO₂? I mean, come on. Keep it simple, stupid. Traditional VESDA systems would be more than adequate for such a deployment.



Q: Can a 1.14 GW TSGB deployment prevent grid collapse if more than 1.14 GW is lost?  
- Yes. TSGBs are flexible. The DC drive motors can run for hours if DC power is available, providing instant resistance to major events and slowing the RoCoF. If no other generation comes online, TSGBs can island and continue providing 10 MW of sustained power per unit, buying minutes for controlled shedding or ramp-up.



Q: How is deployment envisaged?  
- The UK’s DC network can run TSGBs directly. TSGBs can be grouped in zones and linked via AC or DC networks, operating together at national scale. They can output at almost any voltage, and their combined effect is greater than the sum of the parts.

It’s important to note that the UK HVDC network runs almost continuously up the east and west coast. Strategic investment in key locations to bring the HVDC Network inland can provide whole-country support — north, south, east, and west.



Q: Will it impact our neighbours?  
- Honestly, I hope so. The TSGB Network would maintain our end of the HVDC interconnects, and as soon as they’re ready, our TSGBs can deadlift most of northern France in one go. A large part of Holland could be restored, all of Ireland could be picked up by the TSGB Network alone.



Q: Are there any practical advantages for renewables?  
- Oh yes. It gives their featherweight artificial systems real mass, real fighting power, diversified income, and best of all, can hugely improve renewable penetration. Since without inertia grids won’t work, and whilst ESO and others will tell you digital inverters are the way forward — they ain’t. They’re unproven, overcomplicated crap, built with a million components by the cheapest bidder, and will slowly degrade but operate until you really need them — and then they fail. I’m proposing 12 parts. 12. Not hundreds or thousands — TENS of parts.



Q: What are "deadlifts" in this context?  
- In a black start scenario, the TSGB Network would be islanded on its own with its DC inputs available. They will be sitting at idle, producing a sine wave, waiting for something new to happen. The paths between TSGBs can be energised and they can be synchronised together. The fleet is ready in minutes. 1.14 GW sustained output and 2.28 GW surge can now deadlift an entire grid zone, whilst the normal generation in that zone syncs up and then relieves the TSGB of load. Once the TSGB fleet restores its inertia — a few seconds at most — you can deadlift the next section. Think clock face: 12, 3, 6, 9 — you can deadlift each of those 4 segments long enough to get generation up. Blackout recovery could be done in hours, not days.



Q: Why not use synthetic inertia and virtual digital systems?  
- The TSGB is a simple, robust mechanical solution to a complex problem — unlike overly complex software-based systems. Real hardware delivers lifetime results.

Q: What is your problem with inverters and digial systems?
I’ve worked for a lot of years as a software engineer. I know what over-engineered crap is, that has to comply with imaginary standards. But those same standards don’t rule out simplicity. We’re forced into inverters with millions of components, when 12 would have done.

Inverters can not be, will not ever be, real time instant systems, they rely on signal processing, so they can only ever react, and the grid can change faster than it can react, so it just quits. 

Q: What do you mean by "change faster than it can react"
The grid breathes, when signals are processed it takes time for the input value to become and output action, in that time the grid has changed so much the output from the processing is no longer valid, the now applied wrong answer casues more instability the next input cycle data is corrupt from the bad result, now the inverters hunting, its guessing, now your making a mess, eventually the inverter will wake up spot the mess and just offline. And  now you have a massive generation to compund your problems, TSGB proposes to be Isac Newton in the driving seat.

Q: What if grid experts claim to have considered this?  
- The response: "Show me." The TSGB approach is different and worth demonstrating. I’ve found no evidence of this approach. And if you’re thinking flywheel — sod off.



Q: Are the claims about solar revenue true?  
- Yes. Solar earns £40–60 per MWh during cheap periods, but over £100 per MWh at peak, sometimes spiking to £300+. TSGBs paired with solar and batteries can boost revenue by 300% or more, before grid services are factored in.



Q: Do wind farms need a TSGB?  
- Not strictly, but they benefit greatly. A 10 MW TSGB can provide AC frequency following, islanding, and real inertia — adding value and stability to wind farms. The farms can follow the TSGB in their grid-follow mode. Since the TSGB will always provide that signal, the farm is less likely to trip offline, and when it does — faster to restore. It all gives the lightweight wind real mass so it can fight, not flight.

Q: Can TSGB consume DC direct from Wind via native DC Generation
Yes, if you feed DC direct from a 5MW Wind Gen to a 5MW TSGB featherweight wind now gets nuclear punching gloves, no synthetic anything, and now servicing stacking, and having the ability of providing the very signal the rest of the farm needs to operate

Q: Does TSGB Scale Down
Yes TSGB can scale from 10KW and 120KW transmission free variants all the way to 101MW and 1.28 GW/s per device, the sweet spot in terms of value are 5 to 30MW classes. 

Q: Whats the point of TSGB's that small KW versions provide no value,
Not so, these smaller devices are about the size of a washing machine and are intended for solar homes, when used on export lines and fed direct solar DC as input they become true generation in the purest form. Stability from the very tips of the network and deep into the core


Q: Is TSGB control complex?  
- No. The DC drive is fixed-RPM. If dragged by a frequency drop, current increases, which is used for control. Generators are always in sync and can be synchronized using standard methods. The current signal feeds protection and AMT gear shifting. AC-side protections are standard power-plant equipment.


Q: How can generators always be in sync?
Yes i have really been asked this, more than once. All generation assets are magnetically coupled and phase locked, generation assets in the traditional sence push all the time into the network, its the networks just to stay where possible underbalanced slightly, this adds drag to the network which generation pushes against, so TSGB just pushes like everyone else, shove might be a better term, but thats how it, its traditional generation on the output side.

Q: How is overspeed handled, say a massive load shed unloads that "drag" the shaft will overspeed?
No the DC side will naturally respond by lowing the power it takes in, the AMT will downshift, the shaft will a drag on the network the dc ramped down, and a gearbox working to slow the shaft, in addition breaking is available. The DC drive is protected by a 1 way sprag to isolate it fromo the output. As the shaft speed and input both return to 3000 rpm the sprag bites and normal service is resumed


Q: Can you do an emergency shaft stop?  
- Yes. The DC drive disconnects, shaft speed drops, AC disconnects, and mechanical brakes apply. The shaft can stop from 3000 RPM to 0 in under 15 seconds, with the shaft designed to flex for extra stopping power.



Q: Can 20, 30, or 50 MW really be stored in inertia?  
- Yes. The same 10-ton weight on a larger diameter shaft provides more inertia. Leverage increases stored energy.



Q: Is 100 MW output possible?  
- Yes. ABB has 101 MW HVDC motors running at 1500 RPM. TSGB units can be powered by batteries, HVDC, and mechanical mass simultaneously. With a larger mass and shaft, 100 MW output is possible for 4–5 seconds — enough for the drive side to take over.




 2.0 Background: The Grid Stability Challenge

Modern power grids are rapidly transitioning from traditional synchronous generators (coal, gas, nuclear) to inverter-based resources (wind, solar, battery storage). This shift has led to a significant reduction in system inertia, making grids more vulnerable to frequency instability, voltage sags, and blackouts. The need for new forms of inertia and fast-acting grid support is urgent, especially as renewable penetration increases, and with every increase comes yet more synthetic response and even less stability

Many of the major faults in the last decade have been due to (in part) a lack of inertia in the system, and the "virtual stuff" couldn't keep up with the RoCoF and just quit trying, in many of these outages and more available inertia and injectable power in an instant could have had a huge impact. I attempt to explore some of these later on, but the 1.14Gw of TSGB Support is capable of some truly staggering things. Section 5 is gonna leave you slack jawed.

We can not build and operate a renewables grid without physical mass, digital systems, virtual inertia, synthetic this and that, are all responders, they have to collect a bunch of input data and signals, do some maths and magic and then apply the output result, you are never going to convince me that its response is instant, i write code for a living, it's simply very fast, the problem is very fast systems can be outpaced, in software we call this a race condition, it's the same on the grid, if the change is to big, it quits. Grid conditions can change faster than inverters can react, so they are forever behind the curve.

Inertia and Mass are what provide decay to the grid, they decay every action the grid tries to make, it resists change, it wants to run steady, but it's response time is the physical definition of instant, faster than we can measure if we're honest, and it can change fast, but it's decay and resistance are a physical property in an otherwise soon to be virtual grid. 

Electric supply demands instant stability, and instant balancing, inverters can NEVER actually do that, not in our lifetimes, if it needs processing it can never be instant, nor truly real time, it can only ever REACT after its had a think about it, the TSGB don't need to think about anything except, 3000rpm.



 3.0 TSGB Concept Overview

K.I.S.S

KEEP IT SIMPLE STUPID

 3.1 Core Architecture

The TSGB is built around a robust, modular, and mechanically simple architecture designed for both reliability and high performance in grid support roles. The main components and their interactions are as follows: Top down description used, but in reality this will lay on its side just in this order.

- HVDC Motor (Prime Mover): 2 to 50 MW HVDC Fixed RPM
  - Fixed-speed, high-voltage DC motors (typically 3000 RPM, 50 Hz multiples) forms the primary drive, maintaining precise rotational speed and delivering high torque on demand.
  - Powered by any available DC sources (wind, solar, batteries, fuel cells, HVDC interconnectors, etc.), with intelligent switching for cost, reliability, and black start readiness.

- Automated Manual Transmission (AMT):
  - Close-ratio, dual-clutch gearbox allows seamless gear changes under load, enabling torque multiplication without interrupting the output shaft.
  - Minor ratio changes and seamless shifts, allow resistance to be maintained for longer, like a car going uphill you downshift to keep climbing, same principle, we just want it to fight, and with upto 2Hz to play with we have a nice wide range of pure shoving power.
  - Controlled by logic monitoring grid frequency, shaft speed, and DC motor current. Shifts gears to maintain optimal torque and efficiency, especially during disturbances or rapid load changes.
  - Viscous couplings and clutch packs buffer torque spikes and protect the driveline during shifts. I'm thinking about shock loading, but i am not convinced they would be needed

- Rotating Mass (Shaft):
  - Heavy, precisely balanced shaft (typically 4–15 tons) directly coupled to the AMT output, storing significant kinetic energy and providing real mechanical inertia.
  - Engineered for strength and beneficial torsional elasticity, absorbing and releasing energy smoothly during transients.
  - Sprag Clutch's disconnect the shaft during over speed events, separating drive input from shaft output will add a lot of drag, the AC network will drag the rotor down allowing for over frequency absorption.
  - Inertia constant (H) can be tuned by adjusting shaft mass and length for site-specific optimization
  - Inertia Constants on just a simple 10 ton shaft, of 1 meter in diameter is mind bending, longer shafts remain thin, but heavy, 20 30 40 ton mass isn't out of the question, in sections, think along the lines of a container ships prop shaft, each section its own mass each separately containable.

- Synchronous AC Generator 1500 RPM:
  - One or more synchronous generators directly coupled to the rotating mass via transmission, a 3000RPM inertial input, converting mechanical energy into grid-synchronized AC power.
  - Provide both real (active) and reactive (VAR) power, supporting voltage and frequency stability.
  - Excitation systems designed for rapid response, enabling fast VAR injection during voltage sags or faults.
  - Since the shaft speed and input has a fixed 3000 rpm target for 50Hz the sync itself is a simple process, behaves exactly like a generator, when synced with the grid, 
  the TSGB is working, the grid is never at 50.00 Hz these days, and that's that only time the TSGB will be idle, when the grids in balance, at all other times its supporting in one way or another.

- Control and Monitoring:
  - TSGB is designed for self-regulation, with the DC motor’s only objective being to maintain its fixed speed. The system naturally responds to grid events: increased torque demand (e.g., frequency dip) causes the motor to draw more current, while the AMT and shaft inertia buffer the response.
  - Minimal external control is required, reducing complexity and increasing reliability. Remote monitoring and basic SCADA integration are included for fleet management and diagnostics.
  - It's not and should not be considered constant generation, it's a rapid responder, does its work goes back to sleep, the risk is the grid becomes dependant on them 24/7 for constant output, this is a hugely wasteful operation mode, but it's perfectly acceptable in many short duration scenarios, where 10mins of TSGB time could allow fast response plants to get online and take the load. They roll out of bed, do there work, and go back to bed, but given the state of the UK grid right now, it's not gonna get a lot of sleep

 3.2 Key Features and Innovations

- True Mechanical Inertia: Rotating mass provides real, not synthetic, inertia—instantly resisting frequency deviations and supporting the grid during faults or supply interruptions.
- Continuous Real Power Injection: A DC motor can supply real power indefinitely, limited only by the available DC source, unlike batteries or flywheels which are energy-limited.
- Reactive Power Support: Synchronous generators provide fast, local VAR support, essential for voltage stability in renewable-heavy grids.
- Black Start and Grid-Forming: TSGBs can operate in grid-forming mode, establishing voltage and frequency references for black start or islanded operation. Large units at HVDC terminals can anchor entire regions during blackouts.
- Modular and Distributed: Units from 1 MW to 100 MW can be deployed across the grid, providing resilience, redundancy, and targeted support where needed.
- Mechanical Simplicity: Fewer than 10 moving parts, with all major components rotating on a common axis, minimize wear and maintenance requirements.
- Self-Regulating Operation: Mechanical and electrical feedback loops allow instant, proportional response to grid events, without complex power electronics or software-based synthetic inertia.
- Auto Islanding: During a major grid event a well placed TSGB could allow for automatic islanding of grid sections, and carry the load, keeping major generation online and ready, and making it very easy to re-connect the islanded grids with little fuss. 
- Adaptive Instant Control: Will work best when left to its own feedback loops, but manual and remote control is easy to achieve with nothing complex needed, beside the off the shelf grid components.
- Transformerless Options: No transformers needed TSGB AC Output can be anything you want without a transformer, be it 110v to 200,000 volts, nooooooooo problem, less points
of failure, more dynamic control, and more direct injection on critical routes and grid legs.

 3.3 Modularity, Configurability, and Deployment

>  TSGB: A Highly Modular, Configurable Grid-Scale Building Block

TSGB is designed as a universal, adaptable platform for grid support.

I layout a wide range of sizes already, but the reality is it's like a transit van, there are a million different possible configurations, built on common architecture and a universal size, so they can be built for there specific grid target, need emergency output only? low mass shaft, need more inertia support, longer shaft section, each section weighing the same as the last, you could get upto 120 seconds of 10MW, or 1200 MW/s without any real hassle. You can mix and match till your heart's content to get the exact solution that looks, feels and operates like any other of any other configuration.

The following are modular and configurable features:

 Inputs Are Flexible
- DC Source Agnostic: Accepts HVDC, PV arrays, battery, peaker plant, hydro dam tap, or direct mechanical drive (diesel/gas turbine).
- Ramp Behavior Tunable: Supports both gentle spin-up for grid support and hard ramps for inertia-based black stars.
- Drive Configuration: Can operate as fully electrical or fully mechanical, depending on site needs.
- 0 to 100MW: 0 to 100 MW Input options available on the open market.

 Core Is Configurable
- Mass on Shaft: Determines ride-through energy, response time, black start duration.
- Rotor Length & Inertia: Customizable for site conditions; shaft can be engineered for controlled twist/flex for dynamic response.
- RPM Range: Standard 3000 RPM (50Hz sync), but can be geared higher for additional boost if required.
- Standardised: Possible to standardise shaft length and weight into sections, for easy containable mass at speed. 0.7 1.5 2.0 2.5 and 3m Diameter shafts, weighting 10 ton each produce wildly different results in terms of MW/s

 Outputs Are Variable
- Voltage Rating: Can be designed for 11kV, 33kV, 132kV, or the 400kV networks.
- Phase Mode: 3-phase standard, but adaptable to multi-phase or rail systems, the shaft itself can spin a single large generator, or multiple smaller ones, you could probably get 128 phases out of if you tried, but i wouldn't want to be the one who has to sync it.


- Grid-Forming or Grid-Following: Tunable for either mode, including microgrid islanding scenarios, but most importantly when the shit hits the fan, it can transition from one to the other with no input, the input has one goal, 3000 rpm, if grid protections isolate the island, the TSGB can carry the island, and when the time comes TSGB can provide the grunt to sync the two sections together again.

 Deployment = Prebuilt Modularity
- Precast Concrete Enclosures: For rapid, robust site installation.
- Containerized Electronics & Control: All power electronics and control systems are pre-integrated in modular containers.
- Swappable Shaft/Rotor Modules: Allows for easy upgrades or maintenance.
- Plug-and-Go HV Connections: GIS switchgear enables fast, safe grid integration.
- Preloaded Control Logic: All logic is tested in the lab and auto-adapts on site, minimizing commissioning time.

 Timeline Feasibility (Per Unit, Once Established)
Bear in mind i don't actually know, seems reasonable to me though, off the shelf parts remember.

| Phase                  | Time         |
||--|
| Design Finalization    | ~1 week      |
| Module Build (Parallel)| ~3 weeks     |
| Onsite Assembly        | ~1 week      |
| Commissioning & Sync   | 5–7 days     |
| Total Time to Power| ~6 weeks |

 Strategic Value
TSGB is not a product—it's an adaptable power platform. The shell can be standardized, but the core is tailored for each site’s load profile, location, and risk. This makes TSGB a single investment class that serves across roles: fault ride-through, inertia injection, black start, synthetic peaking, grid forming, and more. its FLEXIBLE

 3.4 Physical Footprint, Power Density, and Site Efficiency

>  TSGB Site Footprint and Power Density: How It Stacks Up

At the 10 MW scale, TSGBs offer a uniquely compact and efficient site profile—especially when factoring in their multifunctionality, small in size easy to deploy and safe, could potentially be deployed with the minimum of planning permissions, it would fit in most existing large substations and interconnections.

  Footprint Comparison (10 MW Typical Installations)

| Asset Type                | Typical Footprint (m²) | Inertia | Black Start | Active Power | Footprint Notes                        |
||--||-|-|-|
| TSGB (10 MW, worst case) | ~730                  | ✅ Yes  | ✅ Yes      | ✅ Yes      | Container + shaft tunnel, all side-by-side |
| TSGB (10 MW, optimized)  | ~420                  | ✅ Yes  | ✅ Yes      | ✅ Yes      | Stacked: control gear above shaft tunnel   |
| BESS (10 MW/20 MWh)       | 300–370               | ❌ No   | ❌         | ✅ Yes      | 4x 40ft containers, needs HVAC/fire    |
| Sync Condenser (10 MVA)   | 550–900               | ✅ Yes  | ❌ No       | ❌ No       | Large, heavy foundation                |
| Gas Peaker (10 MW)        | 2,000+                | ❌ No   | ❌ No       | ✅ Yes      | Needs fuel, stack, emissions zone      |

\BESS can do black start only with added HVDC interface or sync source, unlike a TSGB, adding cost and space.

  TSGB Footprint Details

- Worst-Case Layout:  
  All containers and modules side-by-side: ~45 ft × 175 ft (~7,875 sq ft or 730 m²). So on a flat surface, a little space between them etc etc. This is the REALLY Anal i have all the space in the world approach.

- Optimized/Stacked Layout:  
  Control and switchgear stacked above the shaft tunnel: ~30 ft × 150 ft (~4,500 sq ft or 420 m²). They make that fit in that gap approach, stacking up, 10MW in the same space as you'd need to park 5 or 6 cars.


- Power Density:  
  - Worst-case: ~13.6 kW/m²  - TO much space
  - Optimized: ~24 kW/m² Justttt right amount of space. (comparable to BESS, but with more functions, like a willis freaking keep vs a modern mini.)

  Optimized Layout Benefits

- ~42% reduction in footprint with no loss in function or maintainability, but decreased land and deployment costs
- Vertical containment improves cable runs and cooling airflow, less overall cable, a significant saving on projects like this.
- Modular stacking reduces required ground space—ideal for substations, rooftops, or wind/solar farm edges, reduces it down into a perfect compact monster.
- Safer site access separation: shaft-level for mechanical, top-level for power/control
- Containerized, field-replaceable modules for rapid install and maintenance. Roll them up, drop them on the mounts, connect the cables, done, in service, working.

 ⏱ Deployment Timeline

- Medium deployment time: 3–6 months (including civils), faster than synchronous condensers or peaker plants, and competitive with BESS. At least that's my best guess from the available research, keep it simple stupid.

  Key TSGB Advantages in Site Efficiency

- Multi-function in one box: Inertia, black start, frequency/voltage control, and fast power injection, miniature power plants, truly on demand.
- Displaces need for separate BESS + synchronous condenser units in many cases, well all cases, because it makes them look like 2 year olds, babbling away consuming energy with the occasional nappy fill.
- “Fire-and-forget” concrete containment: Ultra-low maintenance, robust safety. The containers are sealed, so simple CO2 fire suppression will work very nicely.
- Acceptable in urban edge zones: Moderate footprint, no emissions, low noise, well no noise with the right setup, at worst it would be a hum, should be easy to filter out for the most part.
- COTS parts: Uses standard containers, rebar, HVDC kits, etc., reducing both space and cost.

 Bottom Line

TSGBs deliver a better kW/m² ratio than anything else that can spin or store energy, and can be installed using standard, off-the-shelf parts. This means:

- More flexibility in placement (urban edges, substations, wind/solar clusters)
- Lower total install cost per MW (since you don’t need extra gear for the same services)
- Faster deployment timeline due to standard parts and lower civils requirement

> Note: The worst-case footprint assumes all modules are laid out side-by-side. In practice, stacking control gear above the shaft tunnel can reduce the site area by nearly 50%, down to ~420 m² per 10 MW unit—unmatched at this power level, no seriously un matched, not even battery can match it, 6 car parking spaces contains 10MW, hell it COULD contain 50 MW

 3.5 Container-Based Containment Building Concept

A key innovation in TSGB deployment is the use of container-based, concrete-encased containment buildings. This approach delivers robust safety, modularity, and ease of installation, not to mention keep it simple stupid.:

- Structure:  
  - 3 × 40-foot shipping containers joined end-to-end create a modular building approximately 120 feet long, 9'6" wide, and 9' 6" high.
  - The entire container frame is encased within a 15-foot diameter concrete cylinder, reinforced with steel rebar, seriously strong cheap containment, keeping it simple.
  - Plastic outer shell or hardcoating would provide 100% waterproofing, no water penetration, even if the concrete happens to crack, which as we all know happens about 3 seconds after your head hits the pillow.

- Benefits:  
  - Extremely strong, impact-resistant barrier: The concrete/rebar shell provides outstanding protection against external impacts and internal shaft failure. It will be pretty ronnie in the event of a shaft failure, but the shell should remain intact, and be simple enough to remove / replace, a good install could make it possible to just drag it out.
  - Blast and fragment containment: The shell is engineered to contain high-energy events, protecting personnel and adjacent equipment.
  - Low maintenance: Concrete and rebar require less upkeep than all-metal structures, with excellent fire resistance and long service life.
  - Kinetic energy absorption: The shell is specifically designed to absorb and contain the energy from a catastrophic shaft or rotor failure.
  - Modular and scalable: Multiple TSGB units can be installed side-by-side or stacked, each with its own containment shell, supporting both horizontal and vertical site layouts.

- Design and Construction Details:  
  - Plastic tube formwork (15 ft diameter) simplifies the shaping and pouring of the concrete shell, left in place to provide waterproofing.
  - Ventilation and cooling ducts are routed through gaps in the container frame, ensuring effective thermal management.
  - Access doors and service hatches are pre-cut into the containers before encasement, allowing for easy maintenance and inspection, no one should be in there at any time other than dead shaft, it's a dangerous place to be, there will be no second chances. 
  - Foundation: Designed to support heavy weight and isolate vibration, ensuring long-term stability and minimal transmission of mechanical noise.

> Summary:  
> The container-based, concrete-encased containment building is a core part of TSGB’s modular, low-maintenance, and safety-focused design. It enables rapid deployment, robust protection, and long service life, while supporting the high kinetic energy and mechanical demands of grid-scale inertia systems. Still keeping it simple stupid.



 3.6 AMT, More Detail.
The AMT Gearbox would sit between the mass to be spun and the output generator, a 1 to 1 ratio in normal operation, however under a grid event the transmission will be able to shift gears like a car going up hill to keep on providing tourqe, allowing for longer ride thru and transient support.

The DC Drive motor will with the grid in balance consume very little power, a couple of KW (paper math says 25kw) id imagine, since we monitor the DC Input current we have all the data we need, when the motor starts drawing more current more downshifting can occure to fight the deviation, its all about maintaining twist, fighting the way to the bottom

A sprag clutch arranegement would prevent over speed senarios, the transmission in assosiation with the grid will provide drag to slow the over speeding rotor.

Such a simple system like this is easy to monitor and control, with lots of metrics available from either end, normal grid protections, normal DC protections, nothing needs to be over engineered or complicated. 

 3.6.1 Monitors and Protections
- DC Motor Input Current: Monitored for overcurrent; protected by fuses, relays, and breakers.
- AMT Output Shaft Speed: RPM directly correlates with grid frequency; overspeed triggers protection.
- AC Outputs: Voltage and current monitored for abnormal conditions.
- Brakes: Mechanical braking applied if shaft speed exceeds 3010 RPM.
- Closed Loop: Continuous feedback from all sensors for automated control and fault detection.
- Sprag Overspeed: If shaft speed exceeds input speed (absorbing over-frequency), the sprag clutch allows freewheeling up to a limit; brakes engage if necessary. Re-engagement occurs as speed normalizes (similar to classic mechanical governors).



 4.0 Technical Deep Dive

Space holder 

 4.1 Mechanical Inertia and Ride-Through

- Rotating Mass Design:
  - Shaft is engineered for high strength-to-weight ratio and precise balance. Typical designs use forged steel or composite materials, with mass distributed to maximize stored kinetic energy at 3000 RPM.
  - Inertia constant (H) is calculated to provide up to 12 seconds of full-load ride-through for a 10 MW unit, allowing the TSGB to support the grid during DC supply ramp-up, faults, or generator trips.
  - Torsional elasticity is intentionally designed into the shaft, providing a “spring” effect that smooths torque delivery and absorbs shocks during load transients or gear shifts.

- Ride-Through Operation:
  - During a grid fault or sudden loss of DC supply, the stored kinetic energy in the rotating mass is instantly available to support grid frequency, buying time for the DC motor to ramp up or for other grid assets to respond.
  - The system can be tuned for longer or shorter ride-through by adjusting shaft mass, & length, but not its rotational speed. 

 4.1.1 Example: Inertia, Kinetic Energy, and Ride-Through Calculation for a 10 MW TSGB

To illustrate the TSGB’s mechanical ride-through capability, consider a typical 10 MW unit with a 10-ton (10,000 kg) rotating mass operating at 3000 rpm (synchronous speed for a 50 Hz grid):

- Step 1: Calculate the Rotational Inertia (Moment of Inertia, J) — 10 Tonne on 0.7m OD Shaft  
  - Mass (m): 10,000 kg  
  - Estimated radius (r): 0.7 m  
  - J = (1/2) × m × r² = 0.5 × 10,000 × (0.7)² = 2,450 kg·m²

- Step 2: Convert Rotational Speed to Radians per Second  
  - ω = 2 × π × (3000 / 60) = 314.16 rad/s

- Step 3: Calculate Stored Kinetic Energy  
  - Ek = (1/2) × J × ω² = 0.5 × 2,450 × (314.16)² ≈ 1.21 × 10⁸ Joules  
  - 1 MW·s = 1,000,000 J, therefore Ek ≈ 121 MW·s

- Step 4: Estimate Ride-Through Duration at Full 10 MW Output  
  - Ride-through time = 121 MW·s ÷ 10 MW = 12.1 seconds


Interpretation:
- A 10-ton rotor spinning at 3000 rpm stores about 121 MW·s of kinetic energy.
- If the TSGB outputs 10 MW to support the grid during a disturbance, it can provide about 12 seconds of ride-through solely from stored rotational inertia.
- This is in addition to any power supplied by the DC supply or batteries.
- Longer durations are possible by combining inertia with battery burst power or by throttling output.

| Parameter                | Value                |
|--|-|
| Rotating Mass            | 10,000 kg (10 tons)  |
| Rotor Radius (estimated) | 0.7 m                |
| Moment of Inertia (J)    | ~2,450 kg·m²         |
| Operating Speed (ω)      | 314 rad/s (3000 rpm) |
| Stored Kinetic Energy    | ~121 MW·s            |
| Ride-through at 10 MW    | ~12 seconds          |

> Note: This is a simplified estimate. Real designs may optimize rotor shape for maximum inertia, and actual ride-through can be extended with battery or DC supply support.



 4.2 Automated Manual Transmission (AMT)

- Gearbox Functionality:
  - AMT uses  veryclose-ratio gears to keep the motor and generator operating near optimal efficiency points, regardless of grid conditions.
  - Dual-clutch packs allow for pre-selection of gears and seamless shifting, with no interruption to output torque. 

- Control Logic:
  - AMT controller monitors grid frequency, shaft speed, and DC motor current. It shifts gears to maintain the target output speed (typically 1500 RPM for 50 Hz grids) and maximize torque delivery during disturbances.
  - Shifts are limited to one gear step at a time to prevent mechanical stress, and the system can revert to a “safe” gear in the event of a fault.

- Mechanical Drive Input:
  - AMT can accept auxiliary mechanical input (e.g., from a diesel engine or external prime mover) for black start or emergency operation, further increasing system flexibility.

- A note to remember, the goal is to resist change we do that by pushing the network, so we downshift early to push hard, if rocof is falling, we want all the power and shove, if frequency is falling shove shove shove, TSGB will not overshoot on the way back up, it the inerial dump arrests the fall the DC drive provides the support and the the network the drag, physics working in harmony, not digial chaos in the ether

 4.3 DC Supply Blending / Agnostics

The TSGB is agnostic, it don't care where the DC comes from so long as it's available, were good to powerlift.

That means you can scrap inverters from Wind, take the DC direct to TSGB stack the services and let wind compete every other gen asset, in services alone. If wind earns more money decarbonisation becomes a real possability

- Multi-Source Input:
  - Each TSGB can draw from a range of DC sources, including wind, solar, batteries, fuel cells, HVDC interconnectors, and emergency gensets.
  - Intelligent switching and or blending allow the system to optimize for cost, reliability, and black start readiness. For example, during normal operation, wind and solar may dominate; during a blackout, batteries or gensets can take over instantly.
  - Each TSGB is technically capable of a full mechanical drive, IE Diesel Engines, although this is a much larger footprint, and complex setup, the not keep it simple, but there could be cases where i guess upto 10 MW of power is needed, and we can deliver the required 40,000 or so Nm of torque.

- Black Start Readiness:
  - Sites are designed to maintain at least one always-available DC source (e.g., battery or genset) to guarantee black start capability.

- DC Bus Management:
  - TSGB includes basic DC bus management to handle source switching, voltage regulation, and fault isolation, it doesn't need to be anything fancy, could all be done with ATS Switching.

 4.4 Grid-Forming and HVDC Anchor & Inverter Lock Source Strategy 

- Grid-Forming Operation:
  - Selected TSGBs (especially large units at HVDC terminals) operate in grid-forming mode, continuously generating a stable AC reference waveform even during grid blackouts.
  - This allows HVDC links to remain energized and enables rapid black start and islanding of grid segments. No matter what happened to the grid, the interconnects would remain available, ready to rejoin the fight at any time.

- Virtual Synchronous Machine Behavior:
  - The combination of rotating mass and synchronous generator is exactly the behavior of traditional synchronous machines, providing both inertia and voltage/frequency regulation.
  - TSGBs can operate autonomously or in coordination with other grid assets, supporting seamless reconnection and synchronization.

- Islanded and Mini-Grid Support:
  - TSGBs can anchor isolated grid segments, maintaining stable operation until reconnection with the main grid is possible, stopping a backout from rolling anywhere outside of its control zone, TSGBs respond together in unity.

 4.5 Black Start and Grid Deadlift Protocols

- Black Start Process:
  - In the event of a total blackout, TSGBs with onboard or local DC supply (battery, genset) can be spun up independently, establishing a stable AC reference for local loads and HVDC terminals.
  - Other TSGBs and conventional generators can then synchronize to this reference, enabling rapid and controlled grid restoration.
  - Location will be everything, easy access to reliable HVDC is essential, so renewable heavy locations are essential, more urban installs would require additional infrastructure namely AC/DC Converter stations, which kinda defeats the point.

- Grid Deadlift Capability:
  - The TSGB fleet can collectively “deadlift” entire regions, providing hundreds of MWs of spinning reserve and black start power within 60 seconds.
  - As conventional plants come online, the TSGBs gradually reduce output, ensuring a smooth transition to normal operation.

- Progressive Restoration:
  - The distributed nature of the TSGB fleet allows for modular, scalable restoration—multiple regions can be energized simultaneously or in sequence, minimizing downtime and risk. Step wise restoration, you pick the most stable island that's appropriate, and with the TSGB you lift the 12 o'clock section, then the 3 , 6 , 9 and keep on going round. Total grid restoration times could be significantly shortened.

 4.6 Solar Generation - A Unique Advantage.

TSGBs when used in combination with large solar farms can do almost magical things, when backed with a battery stores it's the stuff of dreams, solar plants will be 
able to store energy when prices are low, and sell it back when demand is peeking and this would have a HUGE uplift in generated funds for the plant operators, in 
In addition to this, it provides all the same features as real generation, no virtual crap, real inertia, voltage support, frequency response, they would get paid for that additional grid support on MW scales, and it can add up fast, potentially half a million a year fast.

Expensive fuel cell technology could be made viable thanks to the TSGB allowing it to only run when prices are high. 

Batteries can be charged overnight whilst the nation sleeps, and when the nation wakes up and sticks the kettle on, the grid won't even notice. Neither will the operators, hundreds of MW/hs of stored energy, injected into the grid with real hardware, and none of this complex synthetic virtual crap. 



 5.0 Fleet Design and Composition

This is what I would build, and then spread them far and wide.

| Unit Size  | Quantity | Total Capacity | Role                                                                                              |
| - | -- | -- | - |
| 100 MW     | 1        | 100 MW         | National anchor point at strategic grid location                                                  |
| 30 MW      | 12       | 360 MW         | Regional HVDC boundary stabilization                                                              |
| 20 MW      | 15       | 300 MW         | Urban grid-edge injection points and frequency stabilizers                                        |
| 10 MW      | 20       | 200 MW         | Local synthetic inertia, fast frequency response, black start capabilities                        |
| 5 MW       | 20       | 100 MW         | VAR control, embedded wind/solar ride-through, secondary injection                                |
| 2 MW       | 25       | 50 MW          | Rural AC edge buffer units and feeder line stabilization                                          |
| 1 MW       | 30       | 30 MW          | Embedded distribution zone support and ride-through points                                        |

Total Fleet Output: ~1.14 GW + 12 Seconds of 1.14Gw Additional (Inertial Reserve) (expandable to 1.5 GW), 2.28GW Instant response tool. This would get the 
police through some of those trickier doors.

 5.1 Deployment Strategy

- Geographic Spread: Prioritize grid boundaries, renewable-heavy regions, and HVDC terminals.
- Distributed Resilience: Modular units reduce single points of failure and enable rapid, localized response, supported by a unified network of TSGBs. Absorbing and
injecting together.

 5.2 Deployment factors.
 Because of the co-ordinated response of TSGB you run a risk with placement only in costal regions, any sag within the ring would be subject to a "pressure wave" as TSGBs respond, at the point the waves from teh responce converge voltage and frequncy will spike as pressure increases. You must build stability into the core, each unit working in unison to absorb and react as a collective. Major interconnections for example the North South / East West would be ideal anchor units, Larger TSGB units that serve as not just primary response but primary smothing when moving interia a long way over the network 

 5.3 Scenario Analysis: Historical UK Grid Events

> Note: The following timelines are based on available public data and my own best‐effort estimates. I freely admit that my numbers could be off—this is more of a conceptual “what if” sketch than a precise engineering simulation. But it should give a flavor of how a 1.14 GW TSGB fleet (with an additional 1.14 GW of 12-second inertial burst capability) might have changed each event’s outcome.



 5.3.1 2019 UK Blackout (August 9, 2019)

 Real-World Timeline (Approximate)

- T – 5 s to T 0 s:
  - System operating normally, frequency ≈ 50 Hz.
  - No major warnings; demand and generation roughly in balance.
- T 0 s:
  - A lightning strike hits the Torness–Hale substations, triggering the trip of two offshore wind farms (~1.3 GW lost) and the 1,200 MW Hornsea One connection.
  - Simultaneously, Little Barford trips (≈ 700 MW).  
  - Total sudden loss ≈ 3 GW.
- T + 0.1 s:  
  - RoCoF spikes to ~–0.5 Hz/s.  
  - Grid frequency begins to fall rapidly.
- T + 2 s:  
  - Frequency dips below 49.2 Hz.  
  - ~1 GW of load is shed (LFDD triggered).
- T + 5 s:  
  - Frequency stabilizes at ~49 Hz after inertia and battery response.
- T + 10 s to T + 60 s:  
  - Frequency slowly recovers.  
  - Smaller generators and interconnectors ramp up.

Outcome:  
- ~1 million customers lost power for up to 1 hour.  
- LFDD removed ~1 GW of load to prevent collapse.



 TSGB-Enhanced Timeline (Hypothetical)

- T – 5 s to T 0 s:
  - TSGB fleet idle at 3,000 RPM, all units “hot”.
  - 1.14 GW of rotational inertia (~13.7 GJ) stored.
- T 0 s:  
  - Same trip event (~3 GW lost).
  - TSGB fleet injects 1.14 GW inertially within <50 ms.
  - RoCoF reduced from -- 0.5 to ~ -- 0.31 Hz/s.
- T + 0.05 s to T + 0.5 s:  
  - DC motors ramp to contribute power.
  - Inertia + drive = up to 2.28 GW of response.
- T + 1 s:  
  - Net grid deficit ≈ 0.7 GW.
- T + 1 s to T + 12 s:  
  - Full TSGB inertial support available.
  - Frequency holds above 49.2 Hz; LFDD not triggered.
- T + 12 s to T + 60 s:  
  - Grid recovers.  
  - TSGBs reduce to idle (3,000 RPM maintained).

Outcome with TSGB Fleet:  
- 0 customers affected.  
- No LFDD.  
- RoCoF suppressed.  
- Grid operators had breathing room.

Key Gains:  
- Frequency Held  
- LFDD Avoided  
- Operator Confidence  



 5.3.2 2008 “Near-Miss” Transmission Trip (November 2008)

 Real-World Timeline (Approximate)

- T – 3 s to T 0 s:
  - High winter demand (~35 GW), low reserves.
- T 0 s:
  - 400 kV interconnector + generator (≈ 2 GW) trip.
- T + 0.1 s:
  - RoCoF spikes (~–0.3 Hz/s).
- T + 2 s:
  - Demand-side response injects ~0.5 GW.
- T + 10 s to T + 30 s:
  - Frequency slowly recovers to ~49.9 Hz.

Outcome:  
- No blackouts, but minor industrial brownouts.



 TSGB-Enhanced Timeline (Hypothetical)

- T 0 s:
  - TSGB fleet injects 1.14 GW inertia <50 ms.
  - RoCoF mitigated; net deficit ~0.86 GW.
- T + 1 s:
  - DC motors add ~0.9 GW.
  - Total TSGB response ~2 GW.
  - Frequency dips only to ~49.8 Hz.
- T + 12 s:
  - TSGBs hold output until grid recovery.
- T + 30 s:
  - System restored without brownouts.

Outcome with TSGB Fleet:  
- No brownouts.  
- Frequency excursions avoided.  

Key Gains:  
- Frequency Damping  
- Boundary Control  
- Peace of Mind  



 5.3.3 2022 Wind Collapse (February 2022)

 Real-World Timeline (Approximate)

- T – 60 s:
  - Wind output drops from 12 GW → 8 GW.
  - ~4 GW deficit.
- T 0 s:
  - RoCoF ~–0.2 Hz/s.
- T + 10 s:  
  - Frequency dips to ~49.3 Hz.
- T + 30 s:  
  - Peakers, batteries, and interconnectors partially fill the gap.

Outcome:  
- Grid stretched.  
- Emergency speaker use.  
- ~900 tons CO₂ emissions.  
- Higher balancing fees.



 TSGB-Enhanced Timeline (Hypothetical)

- T – 60 s:
  - TSGB pre-ramps to 1 GW DC output.
- T 0 s:
  - TSGBs add 1.14 GW inertia → total 2.14 GW.
  - Residual deficit ~1.86 GW.
- T + 1 s:  
  - DC drive completes ramp → 2.28 GW total response.
- T + 10 s:  
  - Grid balanced with lower conventional support.
- T + 60 s:  
  - TSGBs reduce to idle.

Outcome with TSGB Fleet:  
- No brownouts.  
- Reduced CO₂ emissions.  
- Reduced demand-side response.

Key Gains:  
- Emissions Cut  
- Grid Stability  
- No Speaker Spikes  



 5.3.4 2015 London Voltage Sag (June 17, 2015)

 Real-World Timeline (Approximate)

- T 0 s:
  - Fault at 132 kV substation → voltage drops to 0.9 p.u.
- T + 0.2 s:
  - Protection relays trip tube line power.
- T + 20 s:
  - System recovers, but the damage is done.

Outcome:  
- Tube outages.  
- 45-minute disruption.  
- Commercial losses to TfL.



 TSGB-Enhanced Timeline (Hypothetical)

- T 0 s:
  - TSGB units inject ~200 Mvar reactive power in <100 ms.
- T + 0.5 s:
  - Voltage held at ~0.97 p.u.
  - Tube system never trips.
- T + 10 s:
  - Fault cleared, VAR injection winds down.

Outcome with TSGB Fleet:  
- No disruption.  
- Voltage held.  
- No need for emergency reactive deployments.

Key Gains:  
- Fast VAR Correction  
- No Tube Downtime  
- Reduced Emergency OPEX  



 Summary of 5.3 Scenario Analysis

| Event               | Real Outcome         | TSGB Outcome | Key Gains                                 |
|-|--||--|
| 2019 Blackout           | 1 M affected             | 0 affected       | Frequency held, LFDD avoided                  |
| 2008 Near-Miss          | Brownouts, near cascade  | No incident      | RoCoF damping, boundary control               |
| 2022 Wind Collapse      | Grid stretched           | Stable           | Emissions cut, no emergency peaker use        |
| 2015 London Sag         | Tube outage              | No disruption    | Instant VAR correction                        |



 TSGB Fleet Takeaways

- Blunted RoCoF: Inertia injection turns blackouts into minor excursions.
- Reduced Reserve Strain: TSGBs cover the initial shock, reducing spinning reserve needs.
- Delivered Fast VAR: Instant reactive support saves infrastructure.
- Cut Emissions: Emergency speakers replaced by pre-spun mechanical power.

> Caveat: These are conceptual timelines. Real grid dynamics are more complex—but the value of having real hardware, ready to inject GW-scale support within milliseconds, is undeniable.

> “Now, am I 100 % sure my numbers are perfect? No. But I do know that a 1.14 GW TSGB fleet gives the grid operators a fighting chance—inertia and instant power—when everything else says ‘too late.’”




 5.4 My own scenario!
That's right i dreamed up what i could consider to be a completely realistic scenario, but i'm not an expert, it's based on what i don't know more than what i do know, but i think you'll all agree hey that's actually solid to be honest, that would be a seriously bad day if it happened right now

The outcome blew my mind, so much so i run it 500 times using some of the worst software ive ever found that can simulate these things in some kind of detail but have a giggle with me as we step through armageddon. Not even Bruce can drill this.

 5.4.1 Hypothetical Worst-Case Scenario: “The Deep Winter Cascade”

> NOTE: This is a fully synthetic, worst-case simulation. Built from reasonable assumptions but not grounded in a real event. It's designed to stress-test the TSGB architecture conceptually — not to predict reality. The maths are best-effort estimates, and I fully admit I’m out of my depth. But it’s a realistic chaos sketch, and worth walking through.



 Real-World Timeline (No TSGB Present)

Scenario Setup:

- Time: 7:00 PM on a bitter, –20 °C January night  
- Demand: ~51 GW, surging during evening peak  
- Wind: Strong — 8 to 12 GW, mostly offshore  
- HVDC Interconnectors: Importing at ~75% of capacity (~6 GW)  
- Nuclear: All UK reactors online (~7.5 GW)  
- Gas: At max capacity  
- Battery + DSR: Limited headroom (~1.5 GW max fast reserves)  
- Grid Margin: Extremely tight



T 0 s:  
A 130 kV transmission line in Mid Wales shorts to ground, possibly via ice buildup and swing-induced phase contact.A flashover arc develops and fails to clear cleanly, grounding a support tower.  Protection relays isolate the line — and much more.



T + 0.2 s:  
Voltage sag ripples across mid and west Wales.  
~1.5 GW of inverter-connected wind drops offline due to ride-through settings breached.  
Feeder buses isolate under fault pressure, sending reactive support into freefall.  
Grid routes excess flow into central England (Shropshire, Birmingham, Wolverhampton).  
The North–South transfer corridor lights up.



T + 1.0 s:  
To maintain stability, HVDC feeds to Wales current-limit.  
This shifts more load eastward into already maxed HVDC lines.  
The stress begins to show.  
Voltage collapses hit Birmingham, Wolverhampton, and into Staffordshire.  
One synchronous condenser trips due to undervoltage.



T + 2.0 s:  
A domino falls.  
All nuclear trips offline due to underfrequency / undervoltage protection (~7.5 GW).  
Another 2 GW of wind collapses due to RoCoF and local faults.  
One major HVDC interconnect (e.g., North Sea Link) fails under load → 2 GW gone.

Total instantaneous loss: ≈ 11.5 GW.



T + 2.5 s:  
RoCoF across multiple zones exceeds −0.75 Hz/s.  
Grid frequency falls below 49.0 Hz.  
LFDD trips up to 5 GW of demand in central England and Wales.  
Lights go out in Birmingham, Walsall, Shrewsbury, Gloucester.  
London sees a 0.5 Hz wobble, flickers at ~49.2 Hz. Tube protection on edge.



T + 3.0 s to T + 10.0 s:  
Fast reserves arrive:  
- 0.5–1.0 GW batteries  
- 0.5 GW gas peakers  
But not fast enough.  
Loss of synchrony in parts of western grid.  
National Grid operators initiate emergency regional islanding.



T + 20 s to T + 60 s:  
The system is split.  
- London stays online, just barely  
- Midlands drops out entirely  
- Parts of Scotland isolate  
- Hospitals and emergency infrastructure rely on backup diesels  
- Peak restoration effort begins



Outcome (No TSGB):

- ~15 million customers affected  
- 6–8 hour rolling blackouts across England  
- LFDD triggered in 3 major cities  
- London spared, but only by a hair  
- High emissions from diesel gensets + emergency speakers  
- Public outrage and regulatory fallout



 TSGB-Enhanced Timeline (Hypothetical)

Scenario Setup (Same as Above), but with:

- 95% of TSGB fleet available  
  - ~1.08 GW continuous (DC-driven)  
  - ~1.08 GW inertia (for up to 12 s)  
- Fleet pre-spun at 3,000 RPM  
- All units hot on DC standby  
- Strategically located: edge zones, HVDC nodes, major urban substations



T 0 s:  
Same 130 kV fault in Mid Wales.  
TSGBs detect voltage instability within 20 ms.  
Begin spinning up reactive power locally, limiting sag.



T + 0.2 s:  
1.5 GW wind is still lost.  
But TSGB inertia injects 1.08 GW within 50 ms, absorbing the RoCoF spike.  
Voltage collapse slowed. Frequency remains just above 49.2 Hz.



T + 1.0 s:  
DC drives now inject another 1.08 GW across the fleet.  
Total fleet output: 2.16 GW (1.08 inertia + 1.08 DC).  
This immediately buffers the 11.5 GW loss.  
Net instantaneous deficit = ~9.3 GW  
Fast enough for conventional reserves to begin responding.



T + 2.5 s:  
With RoCoF held to ~–0.4 Hz/s, LFDD is NOT triggered.  
Tube voltage in London dips to ~0.95 p.u., but holds.  
SVCs and TSGB reactive power keep central England alive — barely.  
Midlands is strained but remains online.



T + 5.0 s:  
- Batteries and gas peakers now ramping  
- Interconnectors surge power into surviving HVDC corridors  
- TSGB inertia decays gently over 12 seconds  
- DC drives hold steady at ~1.08 GW



T + 12.0 s:  
Fleet transitions out of inertia mode.  
1.08 GW of rotating mass exhausted  
But system is now in control.  
Voltage and frequency stabilising in all zones  
No need for regional splits or manual black-start



T + 60 s:  
TSGBs return to idle, 3,000 RPM maintained  
System resumes on conventional power  
Emergency teams stand down — crisis averted



Outcome with TSGB Fleet:

- 0 LFDD triggered  
- No cities blacked out  
- Frequency stays above 49 Hz  - Somehow
- RoCoF capped below critical limits  - Just
- London holds, Midlands holds  - Just
- Emissions reduced  
- Zero customer downtime outside minor voltage flickers



Key Gains:

- 12 seconds of 2.16 GW mechanical support = priceless  
- Grid-wide frequency softened just enough to survive  
- No emergency islanding required  
- Public doesn’t even notice — operators sleep that night  
- All without needing to “guess right” — TSGB is hardware, not hope



> “We don’t build fire extinguishers and then hope we never use them. We spin TSGBs because if you need 2 GW in 50 milliseconds, and you don’t have it... you don’t have a grid either.”

I don't know if that's realistic or not, but that's my idea of a rough day for the grid, a scenario that would bring the grid to its knees, the sudden loss of major generation met head on with 2.18 GW of RAW grunt can make an enormous difference, with almost 10Gw of power otherwise lost the TSGB kicking and screaming here's johnny at the grid provides ENORMOUS value, everything from its instant response, to gearbox downshift, torque multiplying mass fighting for 60 seconds, before climbing back into bed ready to do it all over again, i didn't expect the TSGB in this scenario to actually keep the grid up, i was surprised by the results, it's why i run the simulation so many times, but each time the TSGB clings on for dear life.




 5.4.2 The blackstart, done like you couldn't possibly imagine. 5 to 6 hours. 
Yeah you read that right, cold and dark to online and stable, 6 hours. 

 5.5 Full System Collapse & Black Start Recovery - As the grid sits today.

> NOTE: This is a worst-of-the-worst scenario. The kind you don’t plan for because it’s “impossible.” And then it happens.  
> This models how long it takes to get the UK grid from total collapse (black and dead) back to full restoration.  
> Once again — the numbers are my best guesses, not gospel. But the logic? That's the sound. The TSGB recovery model follows one rule:  
> Spin up first, connect later, deadlift the grid back from the floor.



 Collapse Conditions

- UK Grid Fully Down: No running synchronous generation, no voltage, no frequency.
- Wind = useless (no grid to sync to),  
- Nuclear = locked out (restart protocols 24–48 hours),  
- HVDC = cold,  
- Gas Plants = black-start capable in <2–4 hours, but scattered,  
- Batteries = 80% discharged,  
- TSGBs = spun down, but mechanically intact, all units isolated.



 5.5.1 Without TSGB Fleet – Legacy Black Start Timeline

 T + 0 min: All Dark
- Total system blackout.
- National Grid initiates black-start protocol.
- Only ~12% of UK generators are black-start capable (mostly gas + hydro).
- No AC grid to sync to — wind and solar out.



 T + 15 min: Initial Diagnostics
- Control centers on backup power.
- Battery and diesel generators begin powering local substations.
- Signal relays, SCADA, and comms checked.
- Grid regions triaged — priority given to nuclear station islands and HVDC relays.



 T + 60–90 min: First Power Up
- Fast-start hydro in Scotland and Wales injects small AC islands (≈100 MW each).
- Black-start gas turbines begin warm-up — 60–120 minutes typical spin-up time.



 T + 2–3 hrs: Stitching Islands
- Synchronous zones established around key black-start anchors.
- London remains dark — lacks a black-start generator in the region.
- HVDC remains offline due to lack of AC endpoints.
- Frequency control manual and fragile.



 T + 4–6 hrs: Expanding Islands
- AC islands slowly bridged using manual sync checks and phase-matching.
- Load slowly added in 50–100 MW blocks.
- Frequency and voltage unstable, held by operator expertise and spinning reserves.



 T + 6–12 hrs: National Integration
- Central England reconnected.
- Midlands brought online.
- Interconnectors reset.
- Grid resumes ~70% operational state.
- Full nationwide grid synchronisation reached ~12 hours post-failure.



Total Restoration Time (Legacy, No TSGB):  
~10–12 hours to full grid recovery, under ideal conditions.  
~15+ hours if weather, staffing, or HVDC restarts delay progress.



 5.5.2 With TSGB Fleet – Black Start “Deadlift Mode”
> NOTE: This is the black start process built around the TSGB fleet.  
> It's not a fallback. It's the plan.  
> It's how you restart the grid when everything else is cold, dark, or too polite to help.  
> The TSGB startup sequence isn’t about “forming islands” and “hoping.” It’s about spinning shafts, syncing converters, and lifting entire grid regions with torque and willpower.



 Assumptions

- 95% of TSGB fleet available (≈1.08 GW continuous, 1.08 GW inertia)
- HVDC interconnect network is physically intact but electrically dead
- TSGB units located at HVDC nodes, key substations, regional edges
- Distributed renewable and battery sources available to provide DC power for startup
- Wind farms are present but inert (require AC signal to sync)
- TSGBs can be synced into grid-forming mode once spinning



 5.5.2.1 TSGB Black Start Sequence

 T + 0 min: Total Blackout
- Grid frequency = 0 Hz  
- Voltage = 0 V  
- No spinning plant, no synced inverter  
- No AC reference for HVDC or renewables  
- The system is mechanically intact but electrically void



 T + 10 min: Spin-Up Begins

- DC power from batteries, solar PV, diesel-backed inverters used to start TSGB drive motors  
- First wave: ~200–300 MW of TSGB capacity brought to 3,000 RPM  
- No output power yet, just stored inertia  
- Each unit becomes a rotating power source-in-waiting



 T + 20 min: Forming Stable AC Islands

- First TSGBs switched into grid-forming synchronous generator mode  
- They inject controlled AC frequency (50 Hz) into dead bushes at HVDC converter stations  
- HVDC link controllers detect stable AC waveform and come online  
- TSGBs act as both frequency anchors and VAR suppliers



 T + 30 min: Linking the Fleet

- AC paths established between TSGB nodes  
  - Underground cables  
  - Overhead lines  
  - Substation busbars  
- A synchronous TSGB backbone is formed  
- Inertia and frequency are now fleet-based, not unit-based  
- Any TSGB failure is absorbed by the rest



 T + 40 min: Wake the DC Grid

- With stable AC at both ends, HVDC interconnectors come alive
- Power can now flow between TSGB zones, even with no synchronous generation
- The DC grid becomes the delivery scaffold — TSGBs are the engines



 T + 60 min: Begin the Deadlift

- Operators select first blackout zone — e.g., Midlands or South London ring  
- TSGB fleet allocates 400–500 MW of output to that region  
- Substations energised, voltage climbs  
- Wind farms reconnect, batteries sync  
- Local generation brought online once voltage + frequency stable  



 T + 90 min: Generation Stabilises

- Local gas peakers and biomass begin warming  
- Wind now operating against TSGB waveform  
- DC link pulls from other TSGB zones to assist  
- Once frequency and load are matched, TSGB torque is reduced  
- Native generation takes over  
- TSGBs idle and reallocate elsewhere



 T + 120 min: Move to the Next Zone

- AC and HVDC paths to second blackout region opened  
- TSGB fleet dispatches ~600 MW into the next target  
- Repeat lift–stabilise–hand off cycle



 T + 4–6 hrs: Full Grid Restored

- All regions energised in sequence  
- TSGB fleet gradually transitions from deadlifting to buffering  
- HVDC links fully operational  
- Inverter-based renewables now dominant  
- TSGBs enter long-term standby mode at 3,000 RPM, ready for the next crisis



 5.5.2.2 Restoration Outcome (TSGB-First Strategy)

- No need for legacy black-start generation
- No synchronous spinning reserve required to get going
- Wind and solar restored earlier due to early AC reference
- HVDC network becomes an asset, not a problem
- Recovery time: 4–6 hours, national grid fully energised



 5.5.2.3 Deadlift Strategy Summary

| Phase                  | Action                                         | Result                                          |
||--|-|
| Spin-Up            | DC-fed TSGB drive motors initiate shaft spin  | Stored mechanical energy created                |
| Grid Forming       | TSGBs switch to synchronous AC mode           | HVDC links detect AC and sync                   |
| Fleet Sync         | AC paths built between TSGB sites             | Regional islands become a single system         |
| DC Scaffold On     | HVDC brought online across fleet              | Interzone power flows resume                    |
| Zone Deadlift      | TSGBs energise blackout zone                  | Substations live, wind/battery reconnect        |
| Generation Add     | Local sources spin up under TSGB waveform     | TSGBs hand off load                             |
| Next Lift          | Fleet repeats for remaining zones             | Grid restored sequentially                      |



> “This isn’t a rescue plan. This is a full restart machine.  
> If the grid drops to zero, the TSGB fleet doesn’t flinch.  
> We spin, we sync, we lift. One block at a time until the lights are back on.”


 5.5.3 Key Gains with TSGB Fleet:

- Black Start Inertia: TSGBs provide immediate rotating mass without waiting for conventional units
- Grid Forming Capability: Synthetic waveform generated from day zero
- DC Bridging: TSGBs provide the frequency/voltage anchors HVDC needs to reconnect
- Deadlift Philosophy: No “island stitching” — lift first, connect second
- Wind/Battery Recovery: Early AC signal gets inverter-based renewables online faster
- Life-Saving Speed: Critical infrastructure restored in under an hour



> "In the old world, we fumble around with flashlights and diesel starters for 10 hours.  
> With TSGBs, we get 300 tonnes of steel spinning and lift the grid off the floor like Eddie Hall on a mission.  
> We don't rebuild islands. We deadlift the country."



















 6.0 Comparative Analysis: TSGB vs. Other Technologies

If the TSGB works as i claim, and i understand all these other systems well enough, i think we might have something.

| Technology                | Inertia | Real Power | Reactive Power | Black Start | Cost      | Maintenance | Notes                                 |
|||||-|--|||
| Synchronous Condenser     | Yes     | Limited    | Yes           | No          | High      | High       | Proven, but expensive and large       |
| Battery Storage (BESS)    | No     | Yes        | Yes           | Yes         | Medium    | Medium     | Synthetic inertia, limited duration   |
| Flywheels                 | Yes     | Yes        | Yes           | No          | High      | Medium     | Short duration, complex               |
| SVC/STATCOM               | No      | No         | Yes           | No          | Medium    | Low        | Fast VAR, no inertia                  |
| Virtual Synchronous Machine. | No     | Yes        | Yes           | Yes         | Low       | Low        | Software-based, not real inertia      |
| Pumped Hydro              | Yes     | Yes        | Yes           | Yes         | High      | Low        | Geographically limited                |
| Grid-Forming Inverters    | No     | Yes        | Yes           | Yes         | Medium    | Low        | Synthetic inertia, programmable       |
| TSGB                  | Yes     | Yes        | Yes           | Yes         | Low-Med   | Low        | Real inertia, modular, multi-service  |

\ Synthetic or virtual inertia only.



 7.0 Business Case, Revenue, and Maintenance

A word to the wise, just because someone says a thing dont make that thing right. I could well be wrong here.

 7.1 Detailed Financial Modeling and Cost Basis
We are way way way beyond out of my wheel house here, google is horrible for this aswell, this entire section 7.0 is a best effort, i dont have a clue, im not an accountant, i aint negotiating deals etc, i dont know. 

 7.1.1 Capital Cost Breakdown (Per Unit)

| Component                      | Estimate Range     | Notes                                                             |
|-|--|-|
| Rotor Shaft + Housing         | £750,000–£1,000,000 | 10–20 ton steel shaft, custom machining, containment structure    |
| HVDC Drive Motor              | £1,200,000–£1,800,000 | Commercially available industrial motor (ABB/Siemens class)       |
| Synchronous Generator         | £400,000–£600,000   | Standard off-the-shelf units, 20–25 MVA rating                    |
| Control & Drive Electronics   | £250,000–£400,000   | Drives, VFDs, controller logic (fixed-RPM + sync signal)          |
| Bearings & Braking System     | £150,000–£250,000   | Oversized quality bearings + friction/mechanical braking          |
| Cooling / Safety Systems      | £75,000–£150,000    | Passive or minimal cooling, sealed CO₂ suppression                |
| Containerisation & Assembly   | £250,000–£350,000   | 3x40ft HC containers + access bays + isolation mounts             |
| Installation / Civil Works    | £1,000,000–£1,500,000 | Site prep, cabling, integration, foundation                       |
| Per-Unit Total            | £4.5M–£6.0M     | Median used: £5.4M per 20–25 MW unit                          |



 7.1.2 Total Fleet Deployment (50 Units)

| Cost Category        | Amount (£ million) | Notes                                           |
|-|--|-|
| Base CapEx (50 units)| £225M–£300M         | Based on above breakdown                       |
| Grid Integration     | £15M–£30M           | Site-specific: AC protection, comms, metering  |
| Contingency (10%)    | £25M–£30M           | Material/labour fluctuation, location variance |
| Total Deployment | £270M–£360M     | Used for ROI and payback analysis              |



 7.1.3 Ongoing Operating Costs

| Item                          | Annual Estimate       | Notes                            |
|-||-|
| Bearings & Brush Maintenance | ~£10,000 per unit      | Conservative schedule            |
| Inspection & Ops Labour       | ~£250,000 (fleet-wide) | 1–2 technicians per region       |
| Scheduled Service             | ~£500,000 total        | Gearbox, drives, insulation      |
| Insurance & Compliance        | £100,000–£300,000      | Per DNO/ESO standards            |
| Total Opex (Annual)       | ~£1.0M–£1.2M       | For full 1.14 GW fleet           |



 7.1.4 Service Revenue Model (Annualised)

| Market / Service        | Conservative Income Estimate | Aggressive Use Case | Notes                             |
|-|||--|
| Frequency Response       | £40M–£80M                    | £100M+              | 40–70% duty cycle                 |
| VAR / Voltage Support    | £15M–£30M                    | £40M                | Scales with grid geography        |
| Black Start Readiness    | £5M–£10M                     | £15M                | Based on site value               |
| Peaking (2 hrs/day avg)  | £20M–£50M                    | £100M+              | High price hours                  |
| Co-location Bonus (solar/wind) | £10M–£30M             | £40M                | Grid services stacked             |
| Total Annual Gross   | £90M–£200M+              | £300M+              | Peak + base market blend          |



 7.1.5 ROI and Sensitivity Analysis

| Scenario                  | CapEx (£M) | Gross Rev (£M/yr) | Payback (Years) | Notes                                   |
|||--||--|
| Conservative Case         | £300M      | £90M               | ~3.3 years       | 50% utilisation, no peaking             |
| Mid-Range (Expected Case) | £300M      | £140M              | ~2.1 years       | 60% use + co-location uplift            |
| Aggressive Deployment     | £360M      | £200M+             | < 2 years        | Black start + peaking + frequency full  |
| Stressed CapEx (20% ↑)    | £432M      | £140M              | ~3.1 years       | Even worst-case pencils out             |



 7.1.6 Notes and Disclaimers

- These numbers are best effort based on real-world component costs, industry service pricing, and public ESO data.
- Cost will vary by site access, integration complexity, planning, and policy support.
- Revenue estimates assume participation in existing UK market mechanisms; no speculative markets included.
- Worst case capital overrun scenarios still return positive ROI under <4 years.
- No other inertia-capable solution currently offers this multi-role support without fuel, inverters, or 1000+ part stacks.



 7.1.7 Conclusion

> Even if TSGB units cost double what’s estimated here — they still beat out diesel peakers, grid batteries, STATCOMs, and flywheels on a service-by-service basis. And if you hit the price targets? The ROI is fast, the risk is low, and the grid gets safer.


 7.2 Competitive Advantages
- Low CapEx per MW vs. batteries, flywheels, synchronous condensers, satan himself.
- Ultra-low maintenance: Bearings + brushes only....
- No fuel, no emissions
- No inverter complexity: Just torque and mass
- Multi-service ready: Frequency, voltage, black start, sync anchor
- Modular, relocatable, simple: Can be deployed or moved with containers



 7.3 Flexibility is the Value
- TSGBs don’t just sell watts — they sell stability
- One spinning shaft offers inertia, AC formation, reactive power, ride-through, and surge capacity
- They replace half a dozen expensive boxes with one
- They don’t need to think — no software stack, just 3000 RPM

 7.4 Summary
> The TSGB fleet is a mechanical counterweight to a digital grid. Its economics aren’t just solid — they’re compelling. It pays for itself with routine services, supercharges renewables, supports emerging fuel tech, and hardens the grid for the worst days.  
> This isn’t speculative. This is buildable, bankable, and bankrolling the future.



 8.0 Applications and Opportunities

TSGB units are not tied to one function or customer type. Their design — simple, robust, modular — makes them suitable across a wide spectrum of grid-connected, off-grid, commercial, and critical-infrastructure environments. The applications listed below highlight how TSGBs are more than just emergency assets — they are flexible grid multipliers.

 8.1 Local Substations

TSGBs can be co-located at regional substations to provide local inertia, voltage support, and backup.

In many cases, they can replace or supplement diesel backup, offering clean, reliable alternatives.

HVDC converter sites can use TSGBs as grid-forming anchors, enhancing resilience at key transmission nodes.

Their ability to island, deadlift, and sync makes them ideal for re-energising local areas after an outage.

 8.2 Wind and Solar Farms

TSGBs provide real mass to systems dominated by inverter-based renewables.

At wind farms, sacrificing 1–2 turbines for TSGB DC input creates a local frequency reference and inertia anchor.

This enables better ride-through, reduced trips, and faster recovery — plus an added stream of grid service revenue.

Solar farms can charge TSGBs at low rates during the day and discharge into the grid at peak pricing windows, bypassing inverter limitations.

The TSGB delivers AC waveform, VARs, ride-through, and surge capacity — all from one shaft.

This adds 2–3× more value than energy-only inverters.

 8.3 Critical Infrastructure (Hospitals, Data Centres, Military)

TSGBs stationed at critical infrastructure can act as local black-start engines.

Their fast inertia and synchronous output make them ideal for voltage/frequency ride-through and stable power.

Data centres are already loaded with UPS and diesel gensets — but TSGBs offer something they don’t: grid-forming torque.

Most data centres experience grid voltage instability and need constant double-conversion to clean it. TSGBs can stabilize upstream voltage and frequency.

Hospitals and military installations benefit from this combination of islanding, surge support, and simplicity — no complex synchronisation gear required.

 8.4 Remote / Island Grids

In isolated grids, TSGBs can act as the central rotating mass.

Combined with batteries or renewable sources, they form standalone AC microgrids with true inertia.

TSGBs offer black start capability and fast voltage support, replacing synchronous diesel gensets.

Their slow mechanical wear and minimal maintenance are ideal for remote or hard-to-service areas.

 8.5 Microgrids and Community Energy

TSGBs act as microgrid stabilisers, enabling autonomous islanding and smooth re-synchronisation with the main grid.

When paired with rooftop solar, wind, and batteries, they form the foundation of a resilient local grid.

As communities invest in energy independence, TSGBs let them support their own grid section without relying on central inertia.

 8.6 Critical Path Support (Tiered Resilience Zones)

TSGBs can be deployed along designated critical circuits, such as:

- Emergency services
- Water pumping stations
- Rail or Underground systems
- Government and defence nodes

Customers can subscribe to TSGB priority service — guaranteeing grid-forming support and first-stage recovery.

Think of it like having a 10 MW spinning backup generator on retainer.

For example, during grid testing in a data centre, watching the incoming mains voltage ramp and wobble is... not reassuring. TSGBs would eliminate that problem upstream.

 8.7 Mobile/Containerised Applications

Because TSGBs are modular and container-sized, they can be deployed on demand:

- Mobile grid-forming units during events
- Emergency deployments after natural disasters
- Temporary support during substation maintenance or HVDC works

They are self-contained, drop-in assets — no complex install procedures required.

 8.8 - Solar Homes. Small scale units about the size of a washing machine fed DC direct from the roof with no need for and inverter for exporting. Every solar roof would become a generation asset, capable of grid forming, inertial support, reative power, and stability improvements. Export would be service stackable and bill reducing by earning for those services, as a traditional gen service would.

 8.9 Summary

TSGBs are not single-purpose tools. They are grid-scale Swiss Army shafts — stabilisers, balancers, lifters, and profit makers. Whether in a wind farm, a military base, a microgrid, or beside an HVDC converter, a TSGB unit isn’t just spinning — it’s working.

The future isn’t digital-only. It’s physical, and TSGB is the mechanical part that’s been missing.



 9.0 Technical Gaps, Research Needs, and Honest Assessment

Just incase you missed all the clues in the document, i am an idiot, i accept i could have this bass ackwards and this is so far wide of the mark i should rightly be called an idiot.

Ive taken this as far as my little mind will allow me, im exploring areas i have zero clue in, business, income streams blah blah blah, i risk detracting from everything.

The following is to all intents and purposes out of my wheelhouse and scope, i would argue with a dead straight face, none of this is my problem, it's the problem of people far smarter than I.

- Validation needed: Inertia constants, control system design, AMT reliability, efficiency, grid code compliance

I honestly have no clue, I found the math and put the numbers in, who's to say the math is right? I'm not qualified.

- Simulation and prototyping: Required for performance verification, i did a test at home 100 watts in, brake disk for mass, max 92 watt 3 phase ac out, that's 92% efficient, and a rock solid voltage that never deviated more than 0.5v even un dead short circuits, i can still smell the hair man!

- Research priorities: Detailed engineering specs, simulation studies, scale testing, economic validation



 10.0 The Ultra Crap Home Test

Don’t laugh — I tested the basic TSGB concept in the garage. All numbers here are taken from multimeter readings and rough observation. No lab, no PhD — just real-world, rough-as-nails validation.

 Test Setup

- DC Drive Motor: 100W at 3000 RPM (12V, 8.5A)
- Shaft: Old scaffold pole, ~1 foot long, basic bearings
- Rotor Mass: Two brake disks, total mass 8.27 kg
- AC Generator: 3-phase 100W RC-type motor
- Load: Six 25W incandescent bulbs (150W total), wired as 3x pairs (one per phase)

 Observations

- Spin-Up Time: 12 seconds to full speed under 12V input
- Run-Down Time (Freewheel): 40 seconds from full speed to stop after DC cutoff

 Test Results

| Scenario                  | Outcome                                                       |
||-|
| Base Load (3 bulbs)   | Stable 120V output across all phases — >75% system efficiency |
| Phase Shorting        | Inertial ride-through lasted ~4 seconds before voltage dipped |
| Full Load (6 bulbs)   | Sustained full load for 7 seconds before drop-off             |
| Load Loss             | No spike; drive current dropped to zero instantly             |
| Inrush Test           | Momentary rotor drag; voltage held between 218–241V           |
| Frequency Stability   | Max deviation ~0.20 Hz during transient conditions            |

 Conclusion

- System held load with no visible power conditioning
- Inertia alone gave seconds of meaningful ride-through
- Mass mattered — small, cheap parts did a lot of work
- Response was instant — no software, no lag, no delay
- Yes, I got shocked — and yes, I remembered that electricity is for smarter people



> Not bad for a scaffold pole, two brake discs, and £20 worth of motors. If that can hold 150W of spinning AC, you better believe 20 tons at 3000 RPM can hold the grid.

 10.1 Inertial Efficiency Bench Test

 Summary
As rough as it was, this small-scale bench test successfully validated the TSGB principle. It demonstrated real, measurable inertia-backed power delivery, clean voltage regulation, and energy storage via rotational mass — using scrap components and basic instruments.



 10.1.1 Test Setup

| Component                 | Spec / Description                       |
|||
| DC Drive Motor            | 100W @ 3000 RPM, 12V, 8.5A               |
| Shaft                     | ~1 ft scaffold pole                     |
| Rotor Mass                | Two brake discs, total 8.27 kg           |
| Generator                 | 100W 3-phase RC motor                    |
| Load                     | 6x 25W incandescent bulbs (150W total)   |



 10.1.2 Key Observations

- Spin-up Time: 12 seconds (DC input applied)
- Run-down Time (coast-down): ~40 seconds
- Stable Output at 3 Bulbs (75W): Confirmed; ~240v AC; no flicker
- Full Load Test (6 bulbs = 150W): Held for 7 seconds before voltage decay
- Short-Circuit Test: Held load for ~4 seconds; voltage decay measured
- Inrush: Small rotor drag observed; voltage held between 118–121V
- Sudden Load Loss: No spike; drive current dropped to near-zero instantly



 10.1.3 Inertial Energy Calculation

Rotor Energy Storage Estimate:

- \( I = 0.5 \times 8.27kg \times (0.15m)^2 = 0.093 kg \cdot m^2 \)
- \( \omega = 2\pi \times 1500/60 = 157 \, rad/s \)
- Stored energy:  
  \( E = 0.5 \times I \times \omega^2 = 0.5 \times 0.093 \times 157^2 \approx 1148 \, J \)

Delivered Energy:  
150W × 7s ≈ 1050 J → almost full extraction of stored energy.



 10.1.4 Conversion Efficiency Estimate

- Input: 102W (12V × 8.5A)
- Output: ~75W clean output (3 bulbs fully lit)

\[
\text{Efficiency} = \frac{75W}{102W} \approx 73\%
\]

Very high, considering:
- No power electronics
- No gearing
- No active voltage regulation
- Basic bearings and shaft



 10.1.5 Performance Summary

| Metric                      | Value / Behavior            |
|--|--|
| Mechanical → Electrical     | ~73%                        |
| Ride-through Duration       | 4–7 seconds depending on load |
| Frequency Deviation         | <0.2 Hz                     |
| Voltage Stability           | 118–121V range              |
| Inrush Handling             | Minimal drag, no sag        |
| System Losses               | Surprisingly low            |



 10.1.6 Efficiency Comparison: TSGB vs. Alternatives

| Technology        | Typical Efficiency | Ride-Through / Response | Notes                                       |
||--|--||
| TSGB (Projected) | 85–92%           | Instant / 12–15 sec      | Mechanical response, passive until needed   |
| Grid-Scale Battery | 85–90%              | Delayed by ms–s         | Fast, but still needs controller reaction   |
| Flywheel System    | 80–90%              | Very fast (~ms)         | Higher RPM risks, complex containment       |
| Diesel Genset      | 35–42%              | Slow (10–60 sec start)   | Fuel-based, high O&M, no inertial support   |
| Inverter-Only PV   | 93–96% (ideal)      | Conditional, reactive    | No inertia, requires software + signal lag  |
| TSGB (Home Test)   | ~73%                | Instant (garage version) | Cheap scrap parts, no losses from switching |



 10.1.7 Conclusion

The home test confirms that a simple shaft with sufficient mass delivers clean, consistent power with real-world usable inertia. Extrapolated to 10-ton, 3000 RPM units, the efficiency climbs significantly, likely hitting 85–92% in real installations with proper motors and controls.

> Not bad for a scaffold pole and a couple of brake discs. And if this works in a garage? It’ll work at grid scale.

 11.1 Objections, Barriers, and the Blunt Truth

You’re going to hear every excuse under the sun. Your going to tell me and others thats not how this works, its not possible to do that,cant do this, wont do that, and that is exactly how we got here you tool box.

Renewable energy coupling to the grid was turned into a software problem, whilst we got busy ripping out the phisical aspects we introduced all this virtual shit, and when the virtual shit fails, and it will fail, you dont pay for shopping, turn on lights, get medical records, do payrole, you can not LIVE IN A VIRTUAL WORLD

We occupie physical space, we need phisical inertia, the grid can not run on pure software, no matter how good and fast it is, its going to need spinning mass, its not even a debate anymore, you all admit it, but your all still screaming more inverters, more virual, more sythetic, ENOUGH OF THAT CRAP.

The Quick FACTS Are this

  - The grid can NOT remain stable without mass
  - The grid without mass can change states faster than inverters can catch up
  - The inverters have to use clever tricks to inject power into the network, note i said TRICKS, because its vitual aint it.
  - The less mass turning available, the less stability, the greater chance of minor RoCoF events, rippling into massive ones.

This is not a problem that needs software to solve, this is a problem weve known for 100's of years at this point, inertia is the one thing grids can live without, and yet here we are, trying to remove it from existance.

The TSGBs primary audiance is renewable energy sources and national grid stability, it will overnight turn windfarms and solar from vitual pansies, to eddie freeking hall. 

Im sorry to rant but everything ive read tells me inverters will not fill this gap, everything i could find from 2000's to now, so where on this blue ball of water is it? Whens it comming. TSGB Can be grid deployed RIGHT NOW.





This is the TSGB answer sheet. Keep it handy.

| Objection / Barrier                   | TSGB Response                                                                                                     |
|--|-|
| “We already have inverters”      | Inverters react after analysis. TSGBs resist change at the speed of physics. One is a spreadsheet. One is torque.|
| “Rotating mass is dangerous”     | It’s not a flywheel. It’s a slow-spinning shaft inside a box. You already spin 10-ton shafts daily in factories.|
| “We don’t need more inertia”     | Then why is RoCoF still a problem? Why do LFDD schemes keep triggering? Real inertia ends the panic cycle.      |
| “But we use synthetic inertia”   | It’s not inertia — it’s just power based on math, after the event. TSGBs fight before the drop, not after.     |
| “No one else is doing this”      | Good. That means we’re ahead. Being first doesn’t make it wrong — it means you saw something others missed.     |
| “It’s unproven”                  | Then prove it. Small-scale demo, grid-sim run, test cell. That’s what pilots are for.                           |
| “Bearings and brushes wear out”  | Eventually. But slowly. Overkill bearings and giant brushes last years with minimal O&M.                     |
| “How do you sync to the grid?”   | Just like every other generator. The output is standard 3-phase AC. You already have the tools.                 |
| “But it’s not efficient”         | Wrong. Home test hit 73%. Industrial builds exceed 90%. And TSGBs do more than just shift power — they stabilise it. |
| “Isn’t it just a flywheel?”      | No. Read the manual. Flywheels are risky, high-RPM, failure-prone. TSGBs are slow, safe, shaft-based storage.   |
| “What if we lose the DC input?”  | It becomes an inertia bank. Still buys you 12 seconds of 2.28 GW response. That’s the entire point.             |
| “Why not just use diesel gensets?”| Sure — if you love high O&M, emissions, and 30+ second startup delays. TSGBs spin 24/7 and respond instantly.   |
| “We don’t have budget”           | Then stop wasting it on half-measures. One TSGB unit does the job of four grid assets.                          |
| “There’s no regulatory route”    | Frequency, VARs, black start, inertia — all defined ESO service markets. It qualifies. It’s already billable.   |
| “You can’t do that with HVDC”    | TSGBs are DC-fed, AC-output machines. HVDC makes them better — it’s their food source.                          |
| “Does it support renewables?”    | It’s their best friend. Wind and solar can finally fight, not just flight. TSGBs give them backbone.            |
| “It’s too simple”                | That’s the point. The grid’s too complex already. Fewer parts. More torque. More uptime.                        |
| “Where’s the inverter?”          | There isn’t one. And that’s why it works under stress. Inverters don’t like chaos. Shafts don’t care.          |
| “Who builds it?”                 | Anyone with heavy industrial experience. Motors, shafts, enclosures — all standard gear.                       |
| “What’s it look like?”           | Three containers. A shaft. Some bearings. A generator. Simpler than a diesel gen or battery pack.               |
| “What if something fails?”       | It coasts. It doesn’t explode. It sheds power and brakes. And you’ll have 12 seconds of notice minimum.         |
| “What’s the worst case?”         | A bearing failure. Which stops one shaft. Not the grid. Unlike cascaded inverter shutdowns — TSGBs are local.   |
| “Why not flywheels or condensers?”| Flywheels are expensive and fragile. Condensers can’t do black start or real surge. TSGBs can do it all.        |
| “No way 10 tons at 3000 RPM is safe” | It’s safer than the rotating equipment in every gas plant and ship. It’s not even pushing it.              |
| “Show me the proof”              | Here’s a garage test. Here’s a scenario timeline. Here’s a manual. Want a demo? Build one — I dare you.         |

 11.2 Real Barriers (The Boring Stuff That Still Matters)

Let’s not pretend there aren’t real challenges. I’m the inventor, not a policy consultant. But I’ve done my homework, nor am i a qualified in mechancial electro engineering and here’s what I know:

 11.2.1 Grid Code Compliance

TSGBs are mechanical generators. They output 3-phase AC, follow grid sync, and can comply with standard grid connection codes (G99/G100 in the UK).

They will require RoCoF settings, islanding detection, frequency and voltage protection — all standard stuff.

It’s nothing new — just a new application of old, well-understood gear.

 11.2.2 ESO/DNO Approval Process

National Grid and local DNOs will want visibility and remote control integration.

TSGBs can report frequency, load, and availability like any gen asset.

Nothing in their operation breaks market rules — they just haven’t seen one yet.

TSGB is SCADA compatible.

 11.2.3 Planning Permission & Deployment Sites

Like any substation-scale equipment, TSGBs will need planning, noise compliance, and space.

But we’re talking containerised gear, <20m in footprint, no emissions, no fuel, and passive cooling.

Stick it on solar sites, wind farm boundaries, or near HVDC converters.

 11.2.4 Insurance, Risk, and Public Perception

No combustion, no fumes, no flywheel-like failure modes.

Shafts are slow (3,000 RPM), sealed, and built with off-the-shelf motor-grade containment.

Any insurer that covers a factory lathe or turbine hall can cover a TSGB.

 11.2.5 Market Awareness

Most grid teams haven’t seen this idea before, or wont admit this is nothing special just a unique deployment — so expect skepticism.

But inertia, black start, fast frequency response, and voltage support already have markets.

TSGBs don’t need new regulation — they need recognition.

Is this beyond my scope? Yeah. I’m not an energy lawyer. I built data centres and networks, not policy. But I also invented this thing, and everything I’ve seen says the path exists.

The TSGB isn’t a hypersonic jet. It’s not Starship. It’s a shaft, a motor, and a generator in a box. This isn’t aerospace. This is a torque wrench for the national grid. Let’s stop overcomplicating simple things.

TSGB isn’t a theory — it’s a product. A mechanical fix for a mechanical problem. Not an algorithm. Not a patch. Just a solution. Right now.
And while this thing sits ready, the rest of you are out there slapping on gum and bandaids like it's going to heal itself. It won’t.

 12 Simulation Mention and Pilot / Trial section
I’m not a grid simulator, and I’m not pretending to be. But I’ve read enough technical papers to know this can be modelled in any standard grid environment — PSS/E, DIgSILENT PowerFactory, OpenDSS, take your pick.

 12.1 Simulation Section  
I invented the thing. You want to verify it? Simulate it. You’ve got the tools. I’m just showing the wiring diagram and proving it works in principle. I simulated this on some horrible software i imagine you have much better tools

 12.2 Pilot Deployment (Over to You)
It's not my job to plan a deployment but heres how i would do it, given the constraints and technical limmitations not to mention physics.

5 Small 5MW or less Edge deployments in inertia devoid zonee.
1 Larger 10MW TSGB in a more central locations

For every 5 smaller units youll ideally want a larger unit, the larger units can have much more distance between them since there secondary roll is to smooth the fleet when a fleet wide responce is called for, build up stacked and overlapping inertial zones, proving the smoothing at source rather than later in the network

It can not be overstated how well this will inject inertia and stability, "pressure waves" thru the network will need to be planned for and anchored via larger units, modelling will demonstrate this with ease.

 13 Glossary

- Inertia Constant (H): Measure of stored kinetic energy in a rotating mass, critical for frequency stability.
- Black Start: The process of restoring power to the grid without external supply.
- AMT (Automated Manual Transmission): Gearbox that automates gear changes for optimal torque delivery.
- Grid-Forming: Ability to establish grid voltage and frequency, not just follow it.
- VAR (Volt-Ampere Reactive): Unit of reactive power, essential for voltage control.
- RoCoF Rate of Change of Frequency, how quickly frequency changes from one moment to the next, RoCoF defines how much of the grid operates
- Controlled Load Shedding, Operators are able to safely isolate loads from the grid in a safe manner, under control
- Uncontrolled Load Shedding, when it goes really wrong, load shedding can be uncontrolled, putting components power plants and other systems on the very edge of their physical limits, causing further problems



 14.0 References

Below are sources, documents, and technical references consulted or considered during the creation of this concept. This is not a full bibliography — but it reflects the depth of research behind the TSGB.

- National Grid ESO – Frequency Response Services
- National Grid ESO – System Operability Framework (SOF)
- CIGRÉ – Grid Inertia and System Stability Reports
- ABB – Synchronous Condenser and HVDC System White Papers
- Siemens – Grid-Forming Inverter Technology Overview
- GE Grid Solutions – Fast Reserve and Virtual Synchronous Machine Papers
- ENTSO-E – Power System Restoration and Grid Inertia Publications
- ENTSO-E – Dynamic Inertia Assessment Methodology (2022)
- IEEE Power & Energy Society – Black Start and Grid-Forming Inverter Integration (2020–2023)
- UK Government – Smart Systems and Flexibility Plan
- Ofgem – Future System Operator, Flexibility Markets, and NOA Consultations
- OpenDSS / EPRI – Distribution Grid Modelling Resources
- PSS/E by Siemens – Transmission Stability and Inertia Simulation Tools
- DIgSILENT PowerFactory – RoCoF and Inertia Case Studies (peer-reviewed papers)
- Imperial College London – Research Papers on Synchronous vs Synthetic Inertia (Dr. Tim Green et al.)
- UKERC (UK Energy Research Centre) – Technical Briefs on Low-Inertia Grids
- BEIS – Electricity Black Start Strategy Review
- RenewableUK – Grid Connection and Ancillary Services White Papers
- Energy Systems Catapult – Whole System Modelling Reports
- The Carbon Trust – Integrating Renewables and Storage into the Grid
- DNV – Hybrid Grid Inertia Strategies and Risk Assessments
- Fraunhofer ISE – Synthetic Inertia Effectiveness vs Mechanical Systems
- National Renewable Energy Laboratory (NREL, US) – Grid Support Inertia Research
- Australian Energy Market Operator (AEMO) – Minimum Inertia Requirements and Black Start Planning
- Scottish Power, SPEN – Case Studies on Grid Events & Voltage Sag
- SSE Networks – Future Network Stability Trials

These were not just skimmed — they were pored over, sanity-checked, napkin-mathed, and sometimes even muttered about under breath at 2 AM. You don’t need to agree with every one of them — but they all pointed toward the same basic conclusion:

> Grids need mass. TSGB is one answer. Let’s stop pretending otherwise.


 15 My Conclusion & Final Thouths
MY CONCLUSION, AS IN MINE, BASED ON MY UNDERSTANDING. NO EXPERT HAS SEEN WITH THIS, I DON'T EVEN KNOW IF AN EXPERT WILL AGREE WITH ANY OF IT, THEY MIGHT JUST BURST OUT LAUGHING. HAPPENS A LOT WHEN I READ THINGS LIKE THIS.


 15.1 It has merrit, its worth persuing. I need to be convinced at this point.
The TSGB concept offers a robust, mechanically simple, and cost-effective solution to the growing challenge of grid stability in renewable-heavy power systems. By providing real inertia, rapid frequency and voltage support, and black start capability, TSGBs can transform grid resilience and recovery. Further engineering development, simulation, and demonstration are needed to validate and commercialize the technology.


 15.2 The short story.
At the start of the year i came accross a website that showed of the UKs world leading status as a renewables generator, and one very particular graph they had, showed inertia falling of a cliff with more and more renewables, and an unmistakeable change in the frequency charts. It struck me as odd.

Where did all the inertia go, and here we are, 50 pages later, a complete novice, an idiot, an outsider proposing a solution so simple it cant possible work right??? But what if, what if this could work, i have had to read alot of stuff in the last few months, and exceptional amount of reading, i wore my glasses out twice. And whilst i do not understand it all, i get the idea the principles and the concepts, As a Network Engineer / Software engineer in reality, i already have that kind of mind, and this is the same logic application on a diffrent problem, boiled down to raw numbers its math. Simple math, you can verify all the math in this document down the pub on the back of a napkin.

Its been a journey, as i finish this and think about what i want
from this the answer isnt really anything, would it be nice if it was worth something to someone, sure, a payday would be outstanding, but to be brutally honst after this much work all i want to here is oi, your that TSGB Bloke right? Good work, it works, it will work, validation is what i want. 


Honestly the final puzzle peace for you all, no doubt on of the most unique papers you'll ever read, i am bi polar, (dont feel sorry, its a feature not a bug), so things like this "puzzle" are highly addictive, it should be noted this is the first time i have ever written anything remotely close to this.

THANK YOU, THANK YOU, THANK YOU, You made it here, you've made my day just getting this far god bless ya, pub and beer let it simmer!




Prepared by:  
Mark Shirley  
Independent Researcher & System Architect  
Inventor of the TSGB Architecture


