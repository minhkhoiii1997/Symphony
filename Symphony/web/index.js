/* global osmd, opensheetmusicdisplay, symphony */
const $ = x => document.querySelector(x)
window.osmd = new opensheetmusicdisplay.OpenSheetMusicDisplay('container')
window.onresize = () => osmd.render()

// These arrays translate OSMD enums to C++ parseable strings
const notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
const accidentals = ['#', 'b', '', '##', 'bb']

function updateApp () {
  if (window.cppBridge) {
    window.cppBridge.jsGetNote(symphony.getCurrentNote())
  }
}

window.symphony = {
  initialize () {
    osmd.load(`<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE score-partwise PUBLIC "-//Recordare//DTD MusicXML 3.1 Partwise//EN" "http://www.musicxml.org/dtds/partwise.dtd"><score-partwise version="3.1"><work><work-title>Song</work-title></work><identification><encoding><software>MuseScore 3.1.0</software><encoding-date>2019-11-21</encoding-date><supports element="accidental" type="yes"/><supports element="beam" type="yes"/><supports element="print" attribute="new-page" type="yes" value="yes"/><supports element="print" attribute="new-system" type="yes" value="yes"/><supports element="stem" type="yes"/></encoding></identification><defaults><scaling><millimeters>7.05556</millimeters><tenths>40</tenths></scaling><page-layout><page-height>1584</page-height><page-width>1224</page-width><page-margins type="even"><left-margin>56.6929</left-margin><right-margin>56.6929</right-margin><top-margin>56.6929</top-margin><bottom-margin>113.386</bottom-margin></page-margins><page-margins type="odd"><left-margin>56.6929</left-margin><right-margin>56.6929</right-margin><top-margin>56.6929</top-margin><bottom-margin>113.386</bottom-margin></page-margins></page-layout><word-font font-family="FreeSerif" font-size="10"/><lyric-font font-family="FreeSerif" font-size="11"/></defaults><credit page="1"><credit-words default-x="612" default-y="1527.31" justify="center" valign="top" font-size="24">A9 Symphony Demo</credit-words></credit><credit page="1"><credit-words default-x="1167.31" default-y="1427.31" justify="right" valign="bottom" font-size="12"></credit-words></credit><credit page="1"><credit-words default-x="612" default-y="113.386" justify="center" valign="bottom" font-size="8">MIT License</credit-words></credit><part-list><score-part id="P1"><part-name>Piano</part-name><part-abbreviation>Pno.</part-abbreviation><score-instrument id="P1-I1"><instrument-name>Piano</instrument-name></score-instrument><midi-device id="P1-I1" port="1"></midi-device><midi-instrument id="P1-I1"><midi-channel>1</midi-channel><midi-program>1</midi-program><volume>78.7402</volume><pan>0</pan></midi-instrument></score-part></part-list><part id="P1"><measure number="1" width="245.46"><print><system-layout><system-margins><left-margin>0.00</left-margin><right-margin>-0.00</right-margin></system-margins><top-system-distance>170.00</top-system-distance></system-layout></print><attributes><divisions>2</divisions><key><fifths>0</fifths></key><time><beats>4</beats><beat-type>4</beat-type></time><clef><sign>G</sign><line>2</line></clef></attributes><note default-x="79.27" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="120.42" default-y="-15.00"><pitch><step>C</step><octave>5</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="161.56" default-y="-10.00"><pitch><step>D</step><octave>5</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="202.71" default-y="0.00"><pitch><step>F</step><octave>5</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note></measure><measure number="2" width="251.39"><note default-x="10.00" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">begin</beam></note><note default-x="39.97" default-y="-10.00"><pitch><step>D</step><octave>5</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">continue</beam></note><note default-x="69.95" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">continue</beam></note><note default-x="99.92" default-y="-15.00"><pitch><step>C</step><octave>5</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">end</beam></note><note default-x="129.89" default-y="-25.00"><pitch><step>A</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">begin</beam></note><note default-x="159.87" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">continue</beam></note><note default-x="189.84" default-y="-15.00"><pitch><step>C</step><octave>5</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">continue</beam></note><note default-x="219.81" default-y="-25.00"><pitch><step>A</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">end</beam></note></measure><measure number="3" width="176.19"><note default-x="10.00" default-y="-10.00"><pitch><step>D</step><octave>5</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="51.15" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="92.30" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>up</stem></note><note default-x="133.44" default-y="-15.00"><pitch><step>C</step><octave>5</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note></measure><measure number="4" width="269.88"><note default-x="10.00" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">begin</beam></note><note default-x="42.29" default-y="-10.00"><pitch><step>D</step><alter>1</alter><octave>5</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><accidental>sharp</accidental><stem>down</stem><beam number="1">continue</beam></note><note default-x="74.57" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">continue</beam></note><note default-x="106.86" default-y="-15.00"><pitch><step>C</step><octave>5</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>down</stem><beam number="1">end</beam></note><note default-x="139.14" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">begin</beam></note><note default-x="171.43" default-y="-35.00"><pitch><step>F</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">continue</beam></note><note default-x="203.71" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">continue</beam></note><note default-x="236.00" default-y="-25.00"><pitch><step>A</step><octave>4</octave></pitch><duration>1</duration><voice>1</voice><type>eighth</type><stem>up</stem><beam number="1">end</beam></note></measure><measure number="5" width="167.69"><note default-x="10.00" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>up</stem></note><note default-x="50.86" default-y="-20.00"><pitch><step>B</step><octave>4</octave></pitch><duration>2</duration><voice>1</voice><type>quarter</type><stem>down</stem></note><note default-x="91.36" default-y="-30.00"><pitch><step>G</step><octave>4</octave></pitch><duration>4</duration><voice>1</voice><type>half</type><stem>up</stem></note><barline location="right"><bar-style>light-heavy</bar-style></barline></measure></part></score-partwise>`)

    ;(async () => {
      await osmd.render()
      osmd.cursor.show()
      updateApp()
      symphony.showOverlay(false, 'load')
    })()
  },

  getCurrentNote () {
    if (!osmd.cursor.iterator || osmd.cursor.iterator.endReached) {
      return {}
    }

    const note = osmd.cursor.iterator.currentVoiceEntries[0].notes[0]
    const duration = note.length.realValue
    if (!note.pitch) {
      return { duration } // No pitch implies this is a rest. Return only its duration
    }
    const pitch = notes[note.pitch.fundamentalNote] + accidentals[note.pitch.accidental]
    const octave = note.pitch.octave + 3
    return { pitch, octave, duration }
  },

  gotoNextNote () {
    osmd.cursor.next()
    updateApp()
    window.scroll({ top: $('img').getBoundingClientRect().top + window.scrollY - 40 })
  },

  showOverlay (shouldShow, type) {
    const $overlay = $(type === 'freeplay' ? '#freeplay-overlay' : '#load-overlay')
    if (shouldShow) {
      $overlay.classList.remove('hidden')
      window.scroll({ top: 0 })
    } else {
      $overlay.classList.add('hidden')
      window.scroll({ top: $('img').getBoundingClientRect().top + window.scrollY - 40 })
    }
  }
}

// eslint-disable-next-line
new QWebChannel(qt.webChannelTransport, channel => {
  const webobj = channel.objects.cppBridge
  window.cppBridge = webobj
  window.cppBridge.jsLoadXml.connect(async xml => {
    await osmd.load(xml)
    await osmd.render()
    osmd.cursor.show()
    updateApp()
    symphony.showOverlay(false, 'load')
    window.cppBridge.jsFinishSongLoad()
  })
  symphony.initialize()
})
